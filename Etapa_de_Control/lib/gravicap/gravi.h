#ifndef _gravi_h
#define _gravi_h

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "hardware/i2c.h"
#include <stdio.h>
#include <string.h>
#include "ina219.h"

// Estructuras

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
void task_consulta_all(void *params);
void task_encoder(void *pvParameters);
void encoder_isr(uint gpio, uint32_t events);
void task_rele_on();
void status();


#endif // _gravi_h