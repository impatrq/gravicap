#include "gravi.h"
#include "gravi.c"

#include "FreeRTOS.h"
#include "pico/stdlib.h"
#include <stdio.h>


int main(void) {
  
  stdio_init_all();
  sleep_ms(1000);
  multicore_launch_core1(core_1_task);
  printf("hello");

  xTaskCreate(
    task_init, "Task Init",
    512,
    NULL, 
    6,
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x40, "Lectura INA219 0x40 CONSUMIDOR",
    768,
    NULL,
    5, 
    NULL
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x41, "Lectura INA219 0x41 SALIDA DEL MPPT",
    768, 
    NULL,
    5, 
    NULL
  );

  xTaskCreate(
    task_consulta_all, "Consulta",
    2048,
    NULL,
    3,
    NULL 
  );

  xTaskCreate(
    task_lectura_sensor_ina219_0x44, "Lectura INA219 0x44 CONSUMO DE LA BATERÍA",
    768, 
    NULL,
    2, 
    NULL
  );
  
  xTaskCreate(
    task_lectura_sensor_ina219_0x45, "Lectura INA219 0x45 ENTREGA DEL PANEL SOLAR",
    768, 
    NULL,
    2, 
    NULL
  );

  xTaskCreate(
    task_send_uart, "SEND UART PARA ESP8266-01",
    1024,
    NULL,
    1,
    NULL 
  );

  // Arranco el scheduler
  vTaskStartScheduler();

}