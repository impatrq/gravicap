#ifndef _gravi_h
#define _gravi_h

#include "hardware/irq.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "ina219.h"
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "pico/multicore.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
// Estructuras

typedef struct {
    // ina_name es un puntero, referirá a una ubicación
    char* ina_name;
    ina219_t *ina;
    float corriente;
    float voltage;
    float power;
    float shunt;
} mediciones_ina219;

// Función de inicio
void task_init(void *params);

void task_lectura_sensor_ina219_0x40();
void task_lectura_sensor_ina219_0x41();
void task_lectura_sensor_ina219_0x44();
void task_lectura_sensor_ina219_0x45();

// Función que manda a cargar o descargar la batería de
// acuerdo a los datos medidos (espera en queue)
void task_consulta_all(void *params);

// Prende el relé indicado
void task_rele_on(int rele);

// Usando el número de vueltas, le da valores a los test
void status();

// Función del core1
void core_1_task();

// Convierte los leídos en char para mandarlos por uart
void prepare_char_uart(char *ubicacion, mediciones_ina219 *medicion, size_t ubicacion_size, float porcentaje_carga);

// Envía el char que digas por uart a la esp
void task_send_uart(void *params);

#endif // _gravi_h