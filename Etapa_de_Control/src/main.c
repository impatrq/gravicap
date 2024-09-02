#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ina219.h"
#include "gravi.h"
#include "gravi.c"

// Prioridad de tareas = 0 es el más alto

// & es ubicación 
// * es contenido

int main(void) {
  stdio_init_all();
  sleep_ms(1000);

  xTaskCreate(
    task_init,                 // Puntero a funcion para llamar
    "Task Init",               // Nombre para debuggear
    4 * configMINIMAL_STACK_SIZE,   // Espacio en stack reservado mínimo
    NULL,                       // Parametros
    tskIDLE_PRIORITY + 1UL,     // Prioridad mayor que la Idle
    NULL                        // Sin handle
  );

  // Le pido que lea el ina219 0x40, para obtener la corriente del consumidor
  xTaskCreate(
    task_lectura_sensor_ina219,                 // Puntero a funcion para llamar
    "Lectura INA219 0x40 CONSUMIDOR",               // Nombre para debuggear
    4 * configMINIMAL_STACK_SIZE,   // Espacio en stack reservado 
    // Le mando como parámetro la ubicación (&) de una estructura de ina219 para que labure con ese
    (void*) &m_ina0x40,                     // Parametros
    tskIDLE_PRIORITY + 2UL,     // Prioridad mayor que la Idle
    NULL                        // Sin handle
  );

  xTaskCreate(
    task_lectura_sensor_ina219,                 // Puntero a funcion para llamar
    "Lectura INA219 0x41 SALIDA DEL PANEL",               // Nombre para debuggear
    4 * configMINIMAL_STACK_SIZE,   // Espacio en stack reservado 
    // Le mando como parámetro la ubicación (&) de una estructura de ina219 para que labure con ese
    (void*) &m_ina0x41,                     // Parametros
    tskIDLE_PRIORITY + 2UL,     // Prioridad mayor que la Idle
    NULL                        // Sin handle
  );

  xTaskCreate(
    task_rele_on,
    "Relé 1",
    configMINIMAL_STACK_SIZE,
    (void*) &rele_1,
    tskIDLE_PRIORITY + 3UL,     // Prioridad mayor que la Idle
    NULL 
  );

    xTaskCreate(
    task_rele_on,
    "Relé 2",
    configMINIMAL_STACK_SIZE,
    (void*) &rele_2,
    tskIDLE_PRIORITY + 3UL,     // Prioridad mayor que la Idle
    NULL 
  );
  // Arranco el scheduler
  vTaskStartScheduler();
}