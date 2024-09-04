#include "gravi.h"

#define PIN_A 14
#define PIN_B 15

#define rele_1 5// Subida
#define rele_2 6 // Bajada

#define complete_laps 50
#define min_needed_laps 2

// Variables para las mediciones particulares de cada sensor
mediciones_ina219 m_ina0x40;
mediciones_ina219 m_ina0x41;
mediciones_ina219 m_ina0x44;
mediciones_ina219 m_ina0x45;

// Registro de cada sensor
ina219_t ina219_0x40; // Consumo
ina219_t ina219_0x41; // Entrega del panel, salida del motor
ina219_t ina219_0x44; // Consumo de la batería
ina219_t ina219_0x45;

QueueHandle_t queue_ina219;

SemaphoreHandle_t semaphore_encoder = NULL;

volatile int counter = 0;
volatile bool last_A = 0;
int p_r = 600;
float motor_angle;
float lap_counter;
bool test_up, test_down;

// variable de prueba, futuro reemplazo de un sensor
float consumo_motor;
float needed; // Consumo mínimo de los motores, necesario para que empiece a cargar

void task_init(void *params) {
  // Configuración del i2c
  i2c_init(i2c0, 400000);
  gpio_set_function(4, GPIO_FUNC_I2C);
  gpio_set_function(5, GPIO_FUNC_I2C);
  gpio_pull_up(4);
  gpio_pull_up(5);

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
  queue_ina219 = xQueueCreate(2, sizeof(mediciones_ina219));

  semaphore_encoder = xSemaphoreCreateBinary();
  gpio_set_irq_enabled_with_callback(PIN_A, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &encoder_isr);

  // #Inicio el encoder
  gpio_init(PIN_A);
  gpio_set_dir(PIN_A, GPIO_IN);
  gpio_pull_up(PIN_A);

  gpio_init(PIN_B);
  gpio_set_dir(PIN_B, GPIO_IN);
  gpio_pull_up(PIN_B);

  // Elimino la tarea
  vTaskDelete(NULL);
}

// La función de task_lectura_sensor_ina219 trabaja con void *params, puntero en params
// Con el puntero llamo a los datos de esta variable en un void
// Al crear la tarea propiamente llamo al contenido del puntero del void
void task_lectura_sensor_ina219(void *params) {
  while(1){
    ina219_t ina219 = *((ina219_t*)params);

    mediciones_ina219 medicion = *((mediciones_ina219*)params);

    // El ina_name toma la ubicación del puntero ina219, de forma que
    // se modificará automáticamente cada vez que se hagan cambios sobre el original
    medicion.ina_name = &ina219;
    medicion.corriente = ina219_read_current(ina219);
    medicion.voltage = ina219_read_voltage(ina219);
    medicion.power = ina219_read_power(ina219);
    medicion.shunt = ina219_read_shunt_voltage(ina219);

    xQueueSend(queue_ina219, &medicion, pdMS_TO_TICKS(1000));

    vTaskDelay(1000);
  }
}

// Función que pide los estados de corriente de por ahí.
void task_consulta_all(void *params) {
  while(1){
    mediciones_ina219 medicion = *((mediciones_ina219*)params);

    xQueueReceive(queue_ina219, &medicion, pdMS_TO_TICKS(1000));
    // Considero el los valores de consumo de corriente
    status(); // Acá obtengo los valores de los test

    // El panel entrega tensión contante y corriente variable
    if((m_ina0x40.corriente > m_ina0x41.corriente) && (test_up == 0)){

      // Si el consumidor pide más que lo que entrega
      printf("PEDIMOS DE LA RED \n");
      // Cargamos la batería //CONSULTAMOS ESTADO
      task_rele_on(rele_1);
    }

    else if ((m_ina0x40.corriente <= m_ina0x41.corriente) && (test_down == 0)){
      // Si el consumidor pide menos de lo que entrega
      // Descargamos la batería
      task_rele_on(rele_2);

      // Si la corriente generada > a la usada, el sobrante se puede usar para cargar la batería?
      if(((m_ina0x40.corriente - m_ina0x41.corriente) >= needed) && (test_up == 0)){
        // Cargamos la batería
        task_rele_on(rele_1);
      }
    }
  }
}

// Funciones de lectura de los datos del encoder
void task_encoder(void *pvParameters) {
  // Definimos que el peso abajo, es el 0
  while (1) {
    // Espera a que el semáforo sea liberado por la interrupción
    if (xSemaphoreTake(semaphore_encoder, portMAX_DELAY) == pdTRUE) {
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
      motor_angle = (p_r / counter) * 360;
      lap_counter = (p_r / counter);
      printf("Contador: %d\n", counter);
    }
  }
}

void encoder_isr(uint gpio, uint32_t events) {
  // Solo da la señal al semáforo para que la tarea procese el evento
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  xSemaphoreGiveFromISR(semaphore_encoder, &xHigherPriorityTaskWoken);
  portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

// Función para encender el motor solicitado
void task_rele_on() {
  int rele;
  gpio_put(rele, 1);
  printf("relé %d on", rele);
  vTaskDelay(1000);
}

// Función que le da valores a los test, habilitando o no los motores
// en función de los datos obtenidos del encoder
void status(){
  // El peso abajo, está en 0, mientras sube aumenta
  if(lap_counter < min_needed_laps){ 
    // El peso está cerquita del piso
    test_up = 0;
    test_down = 1;
  }
  else if((lap_counter > min_needed_laps) && (lap_counter < (complete_laps - min_needed_laps))){
    // El peso está dentro del rango donde puede hacer cualquier cosa
    test_up = 0;
    test_down = 0;
  }
  else if(lap_counter > (complete_laps - min_needed_laps)){
    // El peso está muy arriba
    test_up = 1;
    test_down = 0;
  }
}