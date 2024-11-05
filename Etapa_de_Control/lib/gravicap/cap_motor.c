#include "gravi.h"
#include "cap_motor.h"

// Variables para las mediciones particulares de cada sensor
extern mediciones_ina219 m_ina0x40;
extern mediciones_ina219 m_ina0x41;
extern mediciones_ina219 m_ina0x44;
extern mediciones_ina219 m_ina0x45;

extern queue_t queue_core_1_motor;

extern float carga, last_carga_motor;

void carga_motor(int rele_carga){
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_STOP, 1);
  gpio_put(RELE_CARGA, 1);

  gpio_put(LED_STOP, 1);
  gpio_put(LED_DESCARGA, 0);
  gpio_put(LED_CARGA, 0);

}

int descarga_motor(){
  //Cuando llamo a descargar el motor
  // primero apago la carga si estuviera prendido
  if(queue_try_peek(&queue_core_1_motor, &carga)){
    last_carga_motor = carga;
    queue_add_blocking (&queue_core_1_motor, &carga);
  }
  else{
    // FALLAS EN EL ENCODER, NO ESTÁ MANDANDO DATOS
    printf("POSIBLE FALLA EN EL ENCODER");
    return 2;
  }
  gpio_put(RELE_STOP, 1);
  gpio_put(RELE_CARGA, 0);
  gpio_put(RELE_DESCARGA, 1);
  
  gpio_put(LED_STOP, 0);
  gpio_put(LED_DESCARGA, 1);
  gpio_put(LED_CARGA, 0);

  if(RELE_CARGA == 1){
    // Si el motor está cargando, cancelamos la carga
    gpio_put(RELE_CARGA, 0);
    if(LED_STOP == 1){
      gpio_put(LED_STOP, 0);
    }
    else if (LED_CARGA == 1){
      gpio_put(LED_CARGA, 0);
    }
  }
  // Prendo y apago
  gpio_put(RELE_DESCARGA, 1);
  gpio_put(LED_DESCARGA, 1);
  gpio_put(RELE_DESCARGA, 0);
  
  // a confirmar si el tiempo es suficiente para que el valor de carga difiera
  if(queue_try_peek(&queue_core_1_motor, &carga)){
    if(last_carga_motor == carga){
      // significa que el motor se frenó y no está descargando
      gpio_put(RELE_DESCARGA, 1);
      gpio_put(RELE_DESCARGA, 0);
      // Luego de recibir un pulso, debería ser suficiente para seguir la descarga
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    return 1;
  }
}

// Función para frenar el motor
void motor_stop() {
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_DESCARGA, 0);
  gpio_put(RELE_STOP, 0); // Al ser un normal cerrado, se mantiene cerrado en 0, está puenteado
  
  gpio_put(LED_STOP, 1);
  gpio_put(LED_DESCARGA, 0);
  gpio_put(LED_CARGA, 0);

  printf("MOTOR EN PAUSA");
}