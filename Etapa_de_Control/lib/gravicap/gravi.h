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

#define RELE_CARGA 6 // Subida
#define RELE_DESCARGA 7 // Bajada
#define RELE_STOP 8 // Parada

#define LED_ENCENDIDO 1  // Led de encendido del sistema

#define LED_2 26 // Led_1 azul del cargador
#define LED_3 15 // Led_2 verde del cargador
#define LED_4 14 // Led_3 verde del cargador
#define LED_5 13 // Led_4 amarillo del cargador
#define LED_6 12 // Led_5 amarillo del cargador
#define LED_7 11 // Led_6 rojo del cargador

#define LED_CARGA 9 // Led de carga blanco
#define LED_DESCARGA 10 // Led de descarga rojo
#define LED_STOP 0 // Led de stop 

#define PIN_A_ENCODER 28 //Encoder
#define PIN_B_ENCODER 29 //Encoder

#define PIN_I2C_1 2 // SDA
#define PIN_I2C_2 3 // SCL

#define PIN_UART_1 4
#define PIN_UART_2 5

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