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
#include "pico/util/queue.h"

#define rele_carga 6 // Subida
#define rele_descarga 7 // Bajada

#define led_1 8 // Led de encendido del sistema

#define led_2 29 // Led_1 azul del cargador
#define led_3 26 // Led_2 verde del cargador
#define led_4 15 // Led_3 verde del cargador
#define led_5 14 // Led_4 amarillo del cargador
#define led_6 13 // Led_5 amarillo del cargador
#define led_7 12 // Led_6 rojo del cargador

#define led_carga 15 // Led de carga blanco
#define led_descarga 26 // Led de descarga rojo
#define led_stop 29 // Led de stop 

#define pin_a_encoder 27 //Encoder
#define pin_b_encoder 28//Encoder

#define pin_i2c_1 2
#define pin_i2c_2 3

#define pin_uart_1 4
#define pin_uart_2 5

#define CHAR_UART 256 // Tamaño de los char para mandar por puerto UART
#define BAUD_RATE 115200

#define complete_laps 50
#define min_critico 20.0

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

void actualizar_leds(float porcentaje_carga);

// Usando el número de vueltas, le da valores a los test
bool status(void);

// Función del core1
void core_1_task(void);

// Convierte los leídos en char para mandarlos por uart
void prepare_char_uart(char *ubicacion, mediciones_ina219 *medicion, size_t ubicacion_size, float porcentaje_carga);

// Envía el char que digas por uart a la esp
void task_send_uart(void *params);

#endif // _gravi_h