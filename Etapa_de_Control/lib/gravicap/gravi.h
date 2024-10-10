#ifndef _gravi_h
#define _gravi_h

#include "hardware/irq.h"
#include "pico/stdlib.h"
//#include <stdint.h> 
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include <string.h>
#include "ina219.h"
#include <math.h>
// Estructuras

typedef struct {
    // ina_name es un puntero, referirá a una ubicación
    ina219_t *ina_name;
    float corriente;
    float voltage;
    float power;
    float shunt;
} mediciones_ina219;

// Función de inicio
void task_init(void *params);

// Función de lectura de ina219, le doy la ubicación de
// una estructura (mediciones) y los datos quedan guardados ahí
void task_lectura_sensor_ina219(void *params);

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
void prepare_char_uart(int value);

// Envía el char que digas por uart a la esp
void send_uart();

#endif // _gravi_h