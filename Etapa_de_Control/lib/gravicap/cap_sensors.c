#include "cap_sensors.h"

// Variables para las mediciones particulares de cada sensor
extern mediciones_ina219 m_ina0x40;
extern mediciones_ina219 m_ina0x41;
extern mediciones_ina219 m_ina0x44;
extern mediciones_ina219 m_ina0x45;

// Registro de cada sensor
extern ina219_t ina219_0x40; // Consumo
extern ina219_t ina219_0x41; // Entrega del mppt
extern ina219_t ina219_0x44; // Consumo de la batería
extern ina219_t ina219_0x45; // Entrega del panel solar

extern QueueHandle_t queue_ina219_consulta_all;
extern QueueHandle_t queue_ina219_send_uart;

void task_lectura_sensor_ina219_0x40(void *params) {
  vTaskDelay(20);
  bool sent_40_all = false, sent_40_uart = false;
  while(1){
    printf("Lectura sensor INA219_0X40\n");
    sent_40_all = false;
    sent_40_uart = false;
    m_ina0x40.ina = &ina219_0x40;

    if(ina219_read_current(ina219_0x40, &m_ina0x40.corriente) == INA219_OK) {

      if(ina219_read_voltage(ina219_0x40, &m_ina0x40.voltage) == INA219_OK) {

        if(ina219_read_power(ina219_0x40, &m_ina0x40.power) == INA219_OK) {

          if (sent_40_all == false) { 
            xQueueSend(queue_ina219_consulta_all, &m_ina0x40, pdMS_TO_TICKS(1000));
            sent_40_all = true;
          }
          if (sent_40_uart == false) { 
            xQueueSend(queue_ina219_send_uart, &m_ina0x40, pdMS_TO_TICKS(1000));
            sent_40_uart = true;
          }
        }
      }
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x41(void *params) {
  vTaskDelay(20);
  bool sent_41_all = false, sent_41_uart = false;
  while(1) {
    sent_41_all = false;
    sent_41_uart = false;
    printf("Lectura sensor INA219_0X41\n");
    m_ina0x41.ina = &ina219_0x41;

    if(ina219_read_current(ina219_0x41, &m_ina0x41.corriente) == INA219_OK) {

      if(ina219_read_voltage(ina219_0x41, &m_ina0x41.voltage) == INA219_OK) {

        if(ina219_read_power(ina219_0x41, &m_ina0x41.power) == INA219_OK) {

          if (sent_41_all == false) { 
            xQueueSend(queue_ina219_consulta_all, &m_ina0x41, pdMS_TO_TICKS(1000));
            sent_41_all = true;
          }
          if (sent_41_uart == false) { 
            xQueueSend(queue_ina219_send_uart, &m_ina0x41, pdMS_TO_TICKS(1000));
            sent_41_uart = true;
          }
        }
      }
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x44(void *params) {
  vTaskDelay(20);
  bool sent_44 = false;
  while(1) {
    sent_44 = false;
    printf("Lectura sensor INA219_0X44\n");
    m_ina0x44.ina = &ina219_0x44;

    if(ina219_read_current(ina219_0x44, &m_ina0x44.corriente) == INA219_OK) {

      if(ina219_read_voltage(ina219_0x44, &m_ina0x44.voltage) == INA219_OK) {

        if(ina219_read_power(ina219_0x44, &m_ina0x44.power) == INA219_OK) {

          if (sent_44 == false) {
            xQueueSend(queue_ina219_send_uart, &m_ina0x44, pdMS_TO_TICKS(1000));
            sent_44 = true;
          }
        }
      }
    }
    vTaskDelay(1000);
  }
}

void task_lectura_sensor_ina219_0x45(void *params) {
  vTaskDelay(20);
  bool sent_45 = false;
  while(1) {
    sent_45 = false;
    printf("Lectura sensor INA219_0X45\n");
    m_ina0x45.ina = &ina219_0x45;

    if(ina219_read_current(ina219_0x45, &m_ina0x45.corriente) == INA219_OK) {

      if(ina219_read_voltage(ina219_0x45, &m_ina0x45.voltage) == INA219_OK) {

        if(ina219_read_power(ina219_0x45, &m_ina0x45.power) == INA219_OK) {

          if (sent_45 == false) {
            xQueueSend(queue_ina219_send_uart, &m_ina0x45, pdMS_TO_TICKS(1000));
            sent_45 = true;
          }
        }
      }
    }
    vTaskDelay(1000);
  }
}