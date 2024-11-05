#ifndef _cap_sensors_h
#define _cap_sensors_h

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"

void task_lectura_sensor_ina219_0x40();
void task_lectura_sensor_ina219_0x41();
void task_lectura_sensor_ina219_0x44();
void task_lectura_sensor_ina219_0x45();

#endif // _cap_sensors_h