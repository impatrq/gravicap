#include "gravi.h"
#include "cap_motor.h"
#include "cap_sensors.h"

// Variables para las mediciones particulares de cada sensor
mediciones_ina219 m_ina0x40;
mediciones_ina219 m_ina0x41;
mediciones_ina219 m_ina0x44;
mediciones_ina219 m_ina0x45;

// Registro de cada sensor
ina219_t ina219_0x40; // Consumo
ina219_t ina219_0x41; // Entrega del mppt
ina219_t ina219_0x44; // Consumo de la batería
ina219_t ina219_0x45; // Entrega del panel solar

// Cadenas de caracteres declaradas para enviar por puerto uart
char uart_consumo[CHAR_UART];
char uart_mppt[CHAR_UART];
char uart_consumo_bat[CHAR_UART];
char uart_panel[CHAR_UART];

// Variables para almacenar lecturas que serán enviadas
float corriente_consumo, entrega_panel, consumo_bat, carga;

QueueHandle_t queue_ina219_consulta_all;
QueueHandle_t queue_ina219_send_uart;

queue_t queue_core_1;
queue_t queue_core_1_motor;

volatile int counter = 0;
volatile bool last_A = 0;
int p_r = 600;
float carga, last_carga_core_1, last_carga_core_0, last_carga_motor, lap_counter;
bool test_up, test_down;

// variable de prueba, futuro reemplazo de un sensor
float needed; // Consumo mínimo de los motores, necesario para que empiece a cargar

int leds_encendidos_previos = -1;  // Inicialmente -1 para asegurar la primera actualización

int leds[6] = {LED_7, LED_6, LED_5, LED_4, LED_3, LED_2};

void task_init(void *params) {

  // Configuración del i2c
  i2c_init(i2c0, 400000);
  gpio_set_function(PIN_I2C_1, GPIO_FUNC_I2C);
  gpio_set_function(PIN_I2C_2, GPIO_FUNC_I2C);
  gpio_pull_up(PIN_I2C_1);
  gpio_pull_up(PIN_I2C_2);

  // Configuración UART1
  uart_init(uart1, BAUD_RATE);  // Configura UART0 con un baud rate de 115200
  gpio_set_function(PIN_UART_1, GPIO_FUNC_UART);  // Configura GPIO4 como TX
  gpio_set_function(PIN_UART_2, GPIO_FUNC_UART);  // Configura GPIO5 como RX
  uart_set_format(uart1, 8, 1, UART_PARITY_NONE);
  // configuro el puerto, N° puerto, 8 bits que se transmiten, 1 bit de parada y sin paridad

  // Pines de salida de los relés
  gpio_set_dir(RELE_CARGA, GPIO_OUT);
  gpio_set_dir(RELE_DESCARGA, GPIO_OUT);
  gpio_set_dir(RELE_STOP, GPIO_OUT);

  // Declaro nombres de cada ina219
  ina219_0x40 = ina219_get_default_config(); // Consumo
  ina219_0x41 = ina219_get_default_config(); // Entrega de la batería, salida del motor
  ina219_0x44 = ina219_get_default_config(); // Consumo de la batería
  ina219_0x45 = ina219_get_default_config(); // Entrea del panel solar

  // Modifico sus direcciones particulares
  ina219_0x41.addr = 0x41;
  ina219_0x44.addr = 0x44;
  ina219_0x45.addr = 0x45;
  
  // Incializo los ina219
  ina219_init(ina219_0x40);
  ina219_init(ina219_0x41);
  ina219_init(ina219_0x44);
  ina219_init(ina219_0x45);
  
  // Calibración de los ina219
  ina219_calibrate(ina219_0x40, 100, 0.8);
  ina219_calibrate(ina219_0x41, 100, 0.8);
  ina219_calibrate(ina219_0x44, 100, 0.8);
  ina219_calibrate(ina219_0x45, 100, 0.8);
  
  // Creo Queue de sensores de FreeRTOS
  queue_ina219_consulta_all = xQueueCreate(2, sizeof(mediciones_ina219));
  queue_ina219_send_uart = xQueueCreate(4, sizeof(mediciones_ina219));
  // Creo Queue ajeno a FreeRTOS
  queue_init(&queue_core_1, sizeof(carga), 1);
  queue_init(&queue_core_1_motor, sizeof(carga), 1);

  // Inicio el encoder
  gpio_init(PIN_A_ENCODER);
  gpio_set_dir(PIN_A_ENCODER, GPIO_IN);
  gpio_pull_up(PIN_A_ENCODER);

  gpio_init(PIN_B_ENCODER);
  gpio_set_dir(PIN_B_ENCODER, GPIO_IN);
  gpio_pull_up(PIN_B_ENCODER);

  // Declaro pines de salida para leds
  gpio_init(LED_ENCENDIDO);
  gpio_set_dir(LED_ENCENDIDO, GPIO_OUT);
  gpio_pull_up(LED_ENCENDIDO);

  gpio_init(LED_2);
  gpio_set_dir(LED_2, GPIO_OUT);
  gpio_pull_up(LED_2);

  gpio_init(LED_3);
  gpio_set_dir(LED_3, GPIO_OUT);
  gpio_pull_up(LED_3);

  gpio_init(LED_4);
  gpio_set_dir(LED_4, GPIO_OUT);
  gpio_pull_up(LED_4);

  gpio_init(LED_5);
  gpio_set_dir(LED_5, GPIO_OUT);
  gpio_pull_up(LED_5);

  gpio_init(LED_6);
  gpio_set_dir(LED_6, GPIO_OUT);
  gpio_pull_up(LED_6);
  
  gpio_init(LED_7);
  gpio_set_dir(LED_7, GPIO_OUT);
  gpio_pull_up(LED_7);

  gpio_init(LED_CARGA);
  gpio_set_dir(LED_CARGA, GPIO_OUT);
  gpio_pull_up(LED_CARGA);

  gpio_init(LED_DESCARGA);
  gpio_set_dir(LED_DESCARGA, GPIO_OUT);
  gpio_pull_up(LED_DESCARGA);

  gpio_init(LED_STOP);
  gpio_set_dir(LED_STOP, GPIO_OUT);
  gpio_pull_up(LED_STOP);

  // Enciendo led de chequeo (ENCENDIDO)
  gpio_put(LED_ENCENDIDO, 1);

  // Aseguro que el motor esté frenado al principio
  motor_stop();

  // Elimino la tarea
  vTaskDelete(NULL);
}

void task_consulta_all(void *params) {
  while(1){
    mediciones_ina219 medicion = *((mediciones_ina219*)params);

    if (xQueueReceive(queue_ina219_consulta_all, &medicion, pdMS_TO_TICKS(1000))) {
      // Considero el los valores de consumo de corriente obtenidos de la cola
      if (status() == 0) {
        // Acá obtengo los valores de los test

        if (m_ina0x40.power > m_ina0x41.power) {
          // Si el consumidor pide más que lo que entrega

          if (test_down == 0) {
            int result = descarga_motor();
            // Si es posible descargar la batería, descargamos
            if (result == 1) {
              vTaskDelay(1000);
            }
            else if (result == 0) {
              // Ya dio su valor de last_carga_motor, down = 1;
              printf("seguimos descargando sin problemas\n");
              vTaskDelay(1000);
            }
          }

          else if (test_down == 1) {
            // Si no es posible descargarla
            motor_stop();
            printf("PEDIMOS DE LA RED \n");
          }
        }
        else if (m_ina0x40.power <= m_ina0x41.power) {
          // Si el consumidor pide menos de lo que entrega o lo mismo

          if ((m_ina0x41.power - m_ina0x40.power) >= needed) { //se puede sumar un margen
            // Si sobra energía y es suficiente para cargar la batería

            if (test_up == 0) {
              // Si la carga puede subir
              // Cargamos la batería
              carga_motor();
            }

            else if (test_up == 1) {
              // No puede subir, entonces nada
              motor_stop();
              printf("100%% DESDE EL PANEL\n");
            }
          }
          else if ((m_ina0x41.power - m_ina0x40.power) < needed) {
            // Pausamos el motor
            motor_stop();
            printf("100%% DESDE EL PANEL\n");
          }
        }
      }
      else if (status() == 1) {
        vTaskDelay(1000);
      }
    }
    else {
      vTaskDelay(1000);
    }
  }
}

void core_1_task(void) {
  last_carga_core_1 == 0;

  while (1) {
    // Leer el estado de las señales A y B
    bool current_A = gpio_get(PIN_A_ENCODER);
    bool current_B = gpio_get(PIN_B_ENCODER);

    // Detectar el flanco ascendente de A
    if (last_A == 0 && current_A == 1) {
      if (current_B == 0) {
        counter++;  // Sentido horario
      } else {
        counter--;  // Sentido antihorario
      }
    }
    last_A = current_A;

    // Cálculo de parámetros
    lap_counter = (counter / p_r);
    carga = (lap_counter * 100) / COMPLETE_LAPS;

    if (fabs(carga - last_carga_core_1) >= 2.5) {
      // Si la diferencia entre la carga actual y la anterior es por lo menos de 2,5%
      // Agrego el dato a una cola (no de freertos)
      queue_add_blocking(&queue_core_1, &carga);

      last_carga_core_1 = carga;
    }
  }
}


// Función para encender los LEDs según el porcentaje de carga
void actualizar_leds(float porcentaje_carga) {
  int leds_encendidos = (int)(porcentaje_carga / 100.0 * 6);

  // Solo actualizar si el número de LEDs encendidos cambia
  if (leds_encendidos != leds_encendidos_previos) {
    // Apagar los LEDs que ya no deben estar encendidos
    for (int i = leds_encendidos; i < 6; i++) {
      gpio_pull_down(leds[i]);
    }

    // Encender los LEDs necesarios
    for (int i = 0; i < leds_encendidos; i++) {
      gpio_pull_up(leds[i]);
    }

    // Actualizar el estado anterior
    leds_encendidos_previos = leds_encendidos;
  }
}

// Función que le da valores a los test, habilitando o no los motores
// en función de los datos obtenidos del encoder, enviados desde el core_1
// La función se bloquea hasta que el porcentaje_carga esté en la cola
bool status(void){
  if (queue_try_peek(&queue_core_1, &carga)) {
    queue_remove_blocking (&queue_core_1, &carga);
    queue_add_blocking (&queue_core_1_motor, &carga);
    if (carga < 100 && carga > 0) {
      actualizar_leds(carga);

      // El peso abajo, está en 0, mientras sube aumenta
      if (carga < MIN_CRITICO) { 
        // El peso está cerquita del piso
        test_up = 0;
        test_down = 1;
      }
      else if ((carga > MIN_CRITICO) && (carga) < (100 - MIN_CRITICO)) {
        // El peso está dentro del rango donde puede hacer cualquier cosa
        test_up = 0;
        test_down = 0;
      }
      else if (carga > (100 - MIN_CRITICO)) {
        // El peso está muy arriba
        test_up = 1;
        test_down = 0;
      }
      else {
        test_up = 1;
        test_down = 1;
      }
      return 0;
    }
    else if (carga < 0 || carga > 100) {
      return 1;
    }
    return 1;
  }
  else {
    return 1;
  }
  return 1;
}

// Convierte los datos leídos
void prepare_char_uart(char *ubicacion, mediciones_ina219 *medicion, size_t ubicacion_size, float porcentaje_carga) {
  // Pongo en 0 el contenido de la cadena
  memset(ubicacion, 0, ubicacion_size);

  snprintf(ubicacion, ubicacion_size,
  "{\"carga\":%.2f,\"nombre\":\"%s\",\"corriente\":%.2f,\"voltage\":%.2f,\"potencia\":%.2f}",
  porcentaje_carga, 
  medicion->ina_name, 
  medicion->corriente, 
  medicion->voltage, 
  medicion->power);
}

// Envía el char que digas por uart a la esp
void task_send_uart(void *params) {
  mediciones_ina219 medicion = *((mediciones_ina219*)params);
  while(true) {
    if (xQueueReceive(queue_ina219_send_uart, &medicion, pdMS_TO_TICKS(1000))) {

      prepare_char_uart(uart_consumo, &m_ina0x40, CHAR_UART, carga);
      prepare_char_uart(uart_mppt, &m_ina0x41, CHAR_UART, carga);
      prepare_char_uart(uart_consumo_bat, &m_ina0x44, CHAR_UART, carga);
      prepare_char_uart(uart_panel, &m_ina0x45, CHAR_UART, carga);

      uart_puts(uart1, uart_consumo);
      uart_puts(uart1, uart_mppt);
      uart_puts(uart1, uart_consumo_bat);
      uart_puts(uart1, uart_panel);
    }
    else {
      vTaskDelay(1000);
    }
  }
}