#include "gravi.h"

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

rele rele_1;
rele rele_2;

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
  gpio_set_dir(rele_1.pin_out, GPIO_OUT);
  gpio_set_dir(rele_2.pin_out, GPIO_OUT);
  
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

  // #Inicio el encoder

  // Elimino la tarea
  vTaskDelete(NULL);
}

// La función de task_lectura_sensor_ina219 trabaja con void *params, puntero en params
// Con el puntero llamo a los datos de esta variable en un void
// Al crear la tarea propiamente llamo al contenido del puntero del void
void task_lectura_sensor_ina219(void *params) {
  ina219_t ina219 = *((ina219_t*)params);

  mediciones_ina219 medicion = *((mediciones_ina219*)params);

  // El ina_name toma la ubicación del puntero ina219, de forma que
  // se modificará automáticamente cada vez que se hagan cambios sobre el original
  if(medicion.ina_name = 0){
    medicion.ina_name = &ina219;
  }
  else{
    medicion.corriente = ina219_read_current(ina219);
    medicion.voltage = ina219_read_voltage(ina219);
    medicion.power = ina219_read_power(ina219);
    medicion.shunt = ina219_read_shunt_voltage(ina219);
  }

  vTaskDelay(1000);
}

// Función que pide los estados de corriente de por ahí.
void task_consulta_all(void *params) {
  // Considero el los valores de consumo de corriente
  
  // El panel entrega tensión contante y corriente variable
  if(m_ina0x40.corriente > m_ina0x41.corriente){

    // Si el consumidor pide más que lo que entrega
    printf("PEDIMOS DE LA RED \n");

    // Cargamos la batería //CONSULTAMOS ESTADO
    task_rele_on(&rele_1);
  }

  else if (m_ina0x40.corriente > m_ina0x41.corriente){
    // Si el consumidor pide menos de lo que entrega
    
    // Descargamos la batería //CONSULTAMOS ESTADO
    task_rele_on(&rele_2);

    if((m_ina0x40.corriente - m_ina0x41.corriente) >= needed){
      // Cargamos la batería //CONSULTAMOS ESTADO
      task_rele_on(&rele_1);
    }
  }


}

// Función de activación de relés para encendido del motor
// La función toma params, usa de variable a la estructura rele
// y la nombra como rele_x.
void task_rele_on(void *params) {
    
    rele rele_x = *((rele*)params);
    gpio_put(rele_x.pin_out, 1);
    printf("relé %d on", rele_x.pin_out);
    vTaskDelay(1000);
}