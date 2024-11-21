if(porcentaje_carga < min_critico)}
else if(porcentaje_carga > (100 - min_critico))
else if((porcentaje_carga > min_critico) && (porcentaje_carga) < (100 - min_critico))
int snprintf(char *buffer, size_t buf_size, const char *format, ...);
void uart_puts(uart_inst_t *uart, const char *s);
BaseType_t xQueueReceive( QueueHandle_t xQueue, void * pvBuffer, TickType_t xTicksToWait );
const configSTACK_DEPTH_TYPE usStackDepth,
task_init, "Task Init",
task_lectura_sensor_ina219_0x40, "Lectura INA219 0x40 CONSUMIDOR",
task_lectura_sensor_ina219_0x41, "Lectura INA219 0x41 SALIDA DEL MPPT",
task_consulta_all, "Consulta",
task_lectura_sensor_ina219_0x44, "Lectura INA219 0x44 CONSUMO DE LA BATERÍA",
task_lectura_sensor_ina219_0x45, "Lectura INA219 0x45 ENTREGA DEL PANEL SOLAR",
task_send_uart, "SEND UART PARA ESP8266-01",