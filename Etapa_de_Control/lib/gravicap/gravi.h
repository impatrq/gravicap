#ifndef _gravi_h
#define _gravi_h

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hardware/i2c.h"
#include <stdio.h>
//#include <math.h>
#include <string.h>
#include "ina219.h"

// Estructuras
typedef struct {
    uint8_t pin_out;
} rele;

typedef struct {
    // ina_name es un puntero, referirá a una ubicación
    ina219_t *ina_name;
    float corriente;
    float voltage;
    float power;
    float shunt;
} mediciones_ina219;

// Funciones nombradas
void task_init(void *params);
void task_lectura_sensor_ina219(void *params);
void task_rele_on(void *params);


#endif // _gravi_h