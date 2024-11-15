#include "gravi.h"
#include "gravi.c"

#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main(void) {
  stdio_init_all();
  multicore_launch_core1(core_1_task);

  xTaskCreate(
    task_init, "Task Init",
    1024,
    NULL, 
    tskIDLE_PRIORITY + 6UL,
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x40, "Lectura INA219 0x40 CONSUMIDOR",
    768,
    NULL,
    tskIDLE_PRIORITY + 5UL, 
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x41, "Lectura INA219 0x41 SALIDA DEL MPPT",
    768, 
    NULL,
    tskIDLE_PRIORITY + 5UL, 
    NULL
  );

  xTaskCreate(
    task_consulta_all, "Consulta",
    2048,
    NULL,
    tskIDLE_PRIORITY + 3UL,
    NULL 
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x44, "Lectura INA219 0x44 CONSUMO DE LA BATERÍA",
    768, 
    NULL,
    tskIDLE_PRIORITY + 2UL, 
    NULL
  );
  
  xTaskCreate(
    task_lectura_sensor_ina219_0x45, "Lectura INA219 0x45 ENTREGA DEL PANEL SOLAR",
    768, 
    NULL,
    tskIDLE_PRIORITY + 2UL, 
    NULL
  );

  xTaskCreate(
    task_send_uart, "SEND UART PARA ESP8266-01",
    512,
    NULL,
    tskIDLE_PRIORITY + 1UL,
    NULL 
  );

// Arranco el scheduler
  vTaskStartScheduler();
}