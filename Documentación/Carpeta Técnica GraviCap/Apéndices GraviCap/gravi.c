#include "gravi.h"

#define rele_1 6 // Subida
#define rele_2 7 // Bajada

#define led_1 8 // Led de encendido del sistema
#define led_2 9 // Led_1 azul del cargador
#define led_3 10 // Led_2 verde del cargador
#define led_4 11 // Led_3 verde del cargador
#define led_5 12 // Led_4 amarillo del cargador
#define led_6 13 // Led_5 amarillo del cargador
#define led_7 14 // Led_6 rojo del cargador
#define led_8 15 // Led de carga blanco
#define led_9 26 // Led de descarga rojo

#define PIN_A 27 //Encoder
#define PIN_B 28 //Encoder

#define CHAR_UART 256 // Tamaño suficiente para almacenar el JSON
#define BAUD_RATE 115200

#define complete_laps 50
#define min_critico 20.0

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
char uart_entrega_panel[CHAR_UART];
char uart_consumo_bat[CHAR_UART];
char uart_carga[CHAR_UART];

// Variables para almacenar lecturas que serán enviadas
float corriente_consumo, entrega_panel, consumo_bat, carga;

QueueHandle_t queue_ina219_consulta_all;
QueueHandle_t queue_ina219_send_uart;

SemaphoreHandle_t semaphore_encoder = NULL;

volatile int counter = 0;
volatile bool last_A = 0;
int p_r = 600;
float motor_angle, carga, last_carga, lap_counter;
bool test_up, test_down;
bool rele1, rele2;

// variable de prueba, futuro reemplazo de un sensor
float needed; // Consumo mínimo de los motores, necesario para que empiece a cargar

void task_init(void *params) {

  // Configuración del i2c
  i2c_init(i2c0, 400000);
  gpio_set_function(2, GPIO_FUNC_I2C);
  gpio_set_function(3, GPIO_FUNC_I2C);
  gpio_pull_up(2);
  gpio_pull_up(3);

  // Configuración UART1
  uart_init(uart1, BAUD_RATE);  // Configura UART0 con un baud rate de 115200
  gpio_set_function(4, GPIO_FUNC_UART);  // Configura GPIO4 como TX
  gpio_set_function(5, GPIO_FUNC_UART);  // Configura GPIO5 como RX
  uart_set_format(uart1, 8, 1, UART_PARITY_NONE);
  // configuro el puerto, uart1, 8 bits que se transmiten, 1 bit de parada y sin paridad

  // Pines de salida de los relés
  gpio_set_dir(rele_1, GPIO_OUT);
  gpio_set_dir(rele_2, GPIO_OUT);
  
  printf("inside");

  // Declaro nombres de cada ina219
  ina219_0x40 = ina219_get_default_config(); // Consumo
  ina219_0x41 = ina219_get_default_config(); // Entrega de la batería, salida del motor
  ina219_0x44 = ina219_get_default_config(); // Consumo de la batería
  ina219_0x45 = ina219_get_default_config();

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
  
  // Creo Queue de sensores
  queue_ina219_consulta_all = xQueueCreate(2, sizeof(mediciones_ina219));
  queue_ina219_send_uart = xQueueCreate(4, sizeof(mediciones_ina219));

  // Inicio el encoder
  gpio_init(PIN_A);
  gpio_set_dir(PIN_A, GPIO_IN);
  gpio_pull_up(PIN_A);

  gpio_init(PIN_B);
  gpio_set_dir(PIN_B, GPIO_IN);
  gpio_pull_up(PIN_B);

  // Declaro pines de salida para leds
  gpio_init(led_1);
  gpio_set_dir(led_1, GPIO_OUT);

  gpio_init(led_2);
  gpio_set_dir(led_2, GPIO_OUT);

  gpio_init(led_3);
  gpio_set_dir(led_3, GPIO_OUT);

  gpio_init(led_4);
  gpio_set_dir(led_4, GPIO_OUT);

  gpio_init(led_5);
  gpio_set_dir(led_5, GPIO_OUT);

  gpio_init(led_6);
  gpio_set_dir(led_6, GPIO_OUT);
  
  gpio_init(led_7);
  gpio_set_dir(led_7, GPIO_OUT);

  gpio_init(led_8);
  gpio_set_dir(led_8, GPIO_OUT);

  gpio_init(led_9);
  gpio_set_dir(led_9, GPIO_OUT);

  // Enciendo led de chequeo (ENCENDIDO)
  gpio_pull_up(led_1);

  // Elimino la tarea
  vTaskDelete(NULL);
}

void task_lectura_sensor_ina219_0x40() {
  while(1){
    bool sent_40_all = false, sent_40_uart = false;
    m_ina0x40.ina = &ina219_0x40;
    m_ina0x40.corriente = ina219_read_current(ina219_0x40);
    m_ina0x40.voltage = ina219_read_voltage(ina219_0x40);
    m_ina0x40.power = ina219_read_power(ina219_0x40);

    if(sent_40_all == false){ 
      xQueueSend(queue_ina219_consulta_all, &m_ina0x40, pdMS_TO_TICKS(1000));
      sent_40_all == true;
    }
    if(sent_40_uart == false){ 
      xQueueSend(queue_ina219_send_uart, &m_ina0x40, pdMS_TO_TICKS(1000));
      sent_40_uart == true;
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x41() {
  while(1){
    bool sent_41_all = false, sent_41_uart = false;

    m_ina0x41.ina = &ina219_0x41;
    m_ina0x41.corriente = ina219_read_current(ina219_0x41);
    m_ina0x41.voltage = ina219_read_voltage(ina219_0x41);
    m_ina0x41.power = ina219_read_power(ina219_0x41);

    if(sent_41_all == false){ 
      xQueueSend(queue_ina219_consulta_all, &m_ina0x41, pdMS_TO_TICKS(1000));
      sent_41_all == true;
    }
    if(sent_41_uart == false){ 
      xQueueSend(queue_ina219_send_uart, &m_ina0x41, pdMS_TO_TICKS(1000));
      sent_41_uart == true;
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x44() {
  bool sent_44 = false;

  while(1){
    m_ina0x44.ina = &ina219_0x44;
    m_ina0x44.corriente = ina219_read_current(ina219_0x44);
    m_ina0x44.voltage = ina219_read_voltage(ina219_0x44);
    m_ina0x44.power = ina219_read_power(ina219_0x44);

    if(sent_44 == false) {
      xQueueSend(queue_ina219_send_uart, &m_ina0x44, pdMS_TO_TICKS(1000));
      sent_44 = true;
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x45() {
  while(1){
    bool sent_45 = false;
    m_ina0x45.ina = &ina219_0x45;
    m_ina0x45.corriente = ina219_read_current(ina219_0x45);
    m_ina0x45.voltage = ina219_read_voltage(ina219_0x45);
    m_ina0x45.power = ina219_read_power(ina219_0x45);

    if(sent_45 == false) {
      xQueueSend(queue_ina219_send_uart, &m_ina0x45, pdMS_TO_TICKS(1000));
      sent_45 = true;
    }
    vTaskDelay(1000);
  }
}

// Función que pide los estados de corriente de por ahí.
void task_consulta_all(void *params) {
  while(1){
    mediciones_ina219 medicion = *((mediciones_ina219*)params);

    xQueueReceive(queue_ina219_consulta_all, &medicion, pdMS_TO_TICKS(1000));
    // Considero el los valores de consumo de corriente obtenidos de la cola
    status(); // Acá obtengo los valores de los test

    if((m_ina0x40.corriente > m_ina0x41.corriente) && (test_up == 0)){

      // Si el consumidor pide más que lo que entrega
      printf("PEDIMOS DE LA RED \n");
      gpio_pull_up(led_2);
      // Cargamos la batería
      task_rele_on(rele_1);
    }

    else if ((m_ina0x40.corriente <= m_ina0x41.corriente) && (test_down == 0)){

      // Si el consumidor pide menos de lo que entrega
      gpio_pull_up(led_3);
      // Descargamos la batería
      task_rele_on(rele_2);

      // Si la corriente generada > a la usada, el sobrante se puede usar para cargar la batería?
      if(((m_ina0x40.corriente - m_ina0x41.corriente) >= needed) && (test_up == 0)){

        gpio_pull_up(led_2);
        // Cargamos la batería
        task_rele_on(rele_1);
      }
    }
  }
}

void core_1_task() {
  last_carga == 0;

  while (1) {
    // Leer el estado de las señales A y B
    bool current_A = gpio_get(PIN_A);
    bool current_B = gpio_get(PIN_B);

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
    //motor_angle = (p_r / counter) * 360;
    lap_counter = (p_r / counter);
    carga = (lap_counter * 100) / complete_laps;

    if (fabs(carga - last_carga) >= 15.0) {
      // Si la diferencia entre la carga actual y la anterior es por lo menos de 15%
      multicore_fifo_push_blocking(carga);
      // Envío bloqueo al core_0 con el dato de la carga
      last_carga = carga;
    }
  }
}

// Función para encender el motor solicitado
void task_rele_on(int rele) {
  gpio_put(rele, 1);
  printf("relé %d on", rele);
  vTaskDelay(1000);
}

// Función que le da valores a los test, habilitando o no los motores
// en función de los datos obtenidos del encoder, enviados desde el core_1
// La función se bloquea hasta que el porcentaje_carga esté en la cola
void status(){
  uint32_t porcentaje_carga = multicore_fifo_pop_blocking();

  // El peso abajo, está en 0, mientras sube aumenta
  if(porcentaje_carga < min_critico){ 
    // El peso está cerquita del piso
    test_up = 0;
    test_down = 1;
  }
  else if((porcentaje_carga > min_critico) && (porcentaje_carga) < (100 - min_critico)){
    // El peso está dentro del rango donde puede hacer cualquier cosa
    test_up = 0;
    test_down = 0;
  }
  else if(porcentaje_carga > (100 - min_critico)){
    // El peso está muy arriba
    test_up = 1;
    test_down = 0;
  }
}

// Convierte los datos leídos por 
void prepare_char_uart(char *ubicacion, mediciones_ina219 *medicion, size_t ubicacion_size, float porcentaje_carga) {
  snprintf(ubicacion, ubicacion_size,
  "{\"carga\":%.2f,\"nombre\":\"%s\",\"corriente\":%.2f,\"voltage\":%.2f,\"potencia\":%.2f}",
  porcentaje_carga, 
  medicion->ina_name, 
  medicion->corriente, 
  medicion->voltage, 
  medicion->power);
}

// Envía el char que digas por uart a la esp
void task_send_uart(void *params){
  mediciones_ina219 medicion = *((mediciones_ina219*)params);
  xQueueReceive(queue_ina219_send_uart, &medicion, pdMS_TO_TICKS(1000));

  prepare_char_uart(uart_consumo, &m_ina0x40, CHAR_UART, carga);
  prepare_char_uart(uart_entrega_panel, &m_ina0x41, CHAR_UART, carga);
  prepare_char_uart(uart_consumo_bat, &m_ina0x44, CHAR_UART, carga);
  prepare_char_uart(uart_carga, &m_ina0x45, CHAR_UART, carga);

  uart_puts(uart1, uart_consumo);
  uart_puts(uart1, uart_entrega_panel);
  uart_puts(uart1, uart_consumo_bat);
  uart_puts(uart1, uart_carga);
}
