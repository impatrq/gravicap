#include "gravi.h"
#include "cap_motor.h"

// Variables para las mediciones particulares de cada sensor
extern mediciones_ina219 m_ina0x40;
extern mediciones_ina219 m_ina0x41;
extern mediciones_ina219 m_ina0x44;
extern mediciones_ina219 m_ina0x45;

extern queue_t queue_core_1_motor;

void carga_motor(int rele_carga){
  gpio_put(rele_descarga, 0);
  gpio_put(rele_stop, 1);
  gpio_put(rele_carga, 1);

  gpio_put(led_stop, 1);
  gpio_put(led_descarga, 0);
  gpio_put(led_carga, 0);

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
  gpio_put(rele_stop, 1);
  gpio_put(rele_carga, 0);
  gpio_put(rele_descarga, 1);
  
  gpio_put(led_stop, 0);
  gpio_put(led_descarga, 1);
  gpio_put(led_carga, 0);

  if(rele_1 == 1){
    // Si el motor está cargando, cancelamos la carga
    gpio_put(rele_1, 0);
    if(led_stop == 1){
      gpio_put(led_stop, 0);
    }
    else if (led_carga == 1){
      gpio_put(led_carga, 0);
    }
  }
  // Prendo y apago
  gpio_put(rele_2, 1);
  gpio_put(led_descarga, 1);
  gpio_put(rele_2, 0);
  
  // a confirmar si el tiempo es suficiente para que el valor de carga difiera
  if(queue_try_peek(&queue_core_1_motor, &carga)){
    if(last_carga_motor == carga){
      // significa que el motor se frenó y no está descargando
      gpio_put(rele_2, 1);
      gpio_put(rele_2, 0);
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
  gpio_put(rele_carga, 0);
  gpio_put(rele_descarga, 0);
  gpio_put(rele_stop, 0); // Al ser un normal cerrado, se mantiene cerrado en 0, está puenteado
  
  gpio_put(led_stop, 1);
  gpio_put(led_descarga, 0);
  gpio_put(led_carga, 0);

  printf("MOTOR EN PAUSA");
}