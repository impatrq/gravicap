
#include "gravi.h"
#include "gravi.c"

#include "hardware/irq.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "ina219.h"
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prioridad de tareas = 0 es el más alto

// & es ubicación 
// * es contenido

int main(void) {
  stdio_init_all();
  multicore_launch_core1(core_1_task);

  xTaskCreate(
    task_init, "Task Init",
    7 * configMINIMAL_STACK_SIZE,
    NULL, 
    tskIDLE_PRIORITY + 1UL,
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x40, "Lectura INA219 0x40 CONSUMIDOR",
    4 * configMINIMAL_STACK_SIZE,
    NULL,
    tskIDLE_PRIORITY + 2UL, 
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x41, "Lectura INA219 0x41 SALIDA DEL MPPT",
    4 * configMINIMAL_STACK_SIZE, 
    NULL,
    tskIDLE_PRIORITY + 2UL, 
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x44, "Lectura INA219 0x44 CONSUMO DE LA BATERÍA",
    4 * configMINIMAL_STACK_SIZE, 
    NULL,
    tskIDLE_PRIORITY + 4UL, 
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x45, "Lectura INA219 0x45 ENTREGA DEL PANEL SOLAR",
    4 * configMINIMAL_STACK_SIZE, 
    NULL,
    tskIDLE_PRIORITY + 4UL, 
    NULL
  );

  xTaskCreate(
    task_consulta_all, "Consulta",
    configMINIMAL_STACK_SIZE,
    NULL,
    tskIDLE_PRIORITY + 3UL,
    NULL 
  );

  xTaskCreate(
    task_send_uart, "SEND UART PARA ESP8266-01",
    4 * configMINIMAL_STACK_SIZE,
    NULL,
    tskIDLE_PRIORITY + 3UL,
    NULL 
  );

// Arranco el scheduler
  vTaskStartScheduler();
}