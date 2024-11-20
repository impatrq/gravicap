#include "cap_motor.h"

// Variables para las mediciones particulares de cada sensor
extern mediciones_ina219 m_ina0x40;
extern mediciones_ina219 m_ina0x41;
extern mediciones_ina219 m_ina0x44;
extern mediciones_ina219 m_ina0x45;

extern queue_t queue_core_1_motor;

extern float carga, last_carga_motor;

int down = 0;

void carga_motor(int rele_carga) {
  down = 0;
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_STOP, 1);
  gpio_put(RELE_CARGA, 1);

  gpio_put(LED_STOP, 1);
  gpio_put(LED_DESCARGA, 0);
  gpio_put(LED_CARGA, 0);
  return;
}

int descarga_motor() {
  if (down == 0) {
    // Cuando llamo a descargar el motor

    // Configuro relés y leds para el estado de descarga
    gpio_put(RELE_STOP, 1);
    gpio_put(RELE_CARGA, 0);
    gpio_put(RELE_DESCARGA, 1);
    
    gpio_put(LED_STOP, 0);
    gpio_put(LED_DESCARGA, 1);
    gpio_put(LED_CARGA, 0);

      // Trato de recoger los datos de una queue con los datos
      // la última carga del motor y la más reciente
    if (queue_try_peek(&queue_core_1_motor, &carga)) {
      queue_remove_blocking (&queue_core_1_motor, &carga);
      last_carga_motor = carga;
    }
    else {
      // FALLAS EN EL ENCODER, NO ESTÁ MANDANDO DATOS
      printf("POSIBLE FALLA EN EL ENCODER NO HAY TRANSFERENCIA DE DATOS\n");
      return 2;
    }

    gpio_put(RELE_DESCARGA, 0);
    // YA RECIBIÓ SU PRIMER VALOR DE CARGA
    // Y DIO UN PULSO DE DESCARGA
    down = 1;
    return 0; // lleva a un delay
  }
  else if (down == 1) {
    if (queue_try_peek(&queue_core_1_motor, &carga)) {
      queue_remove_blocking(&queue_core_1_motor, &carga);
    }
    else {
      printf("POSIBLE FALLA EN EL ENCODER NO HAY TRANSFERENCIA DE DATOS\n");
      return 2;
    }
    
    // YA TRATÓ DE DESCARGAR UNA VEZ SIN PASAR POR UNA CARGA O STOP
    if (last_carga_motor == carga) {
      // No está descargando
      gpio_put(RELE_DESCARGA, 1);
      gpio_put(RELE_DESCARGA, 0);
      return 1; // delay
    }
    else {
      // debería estar descargando, lo llevo a un delay
      return 1; // delay
    }

  }
  else {
    return 1;
  }
}

// Función para frenar el motor
void motor_stop() {
  down = 0;
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_STOP, 0); // Al ser un normal cerrado, se mantiene cerrado en 0, está puenteado
  
  gpio_put(LED_STOP, 1);
  gpio_put(LED_DESCARGA, 0);
  gpio_put(LED_CARGA, 0);

  printf("MOTOR EN PAUSA\n");
  return;
}