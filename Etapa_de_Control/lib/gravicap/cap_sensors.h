#ifndef _cap_sensors_h
#define _cap_sensors_h

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

#include "gravi.h"

void task_lectura_sensor_ina219_0x40(void *params);
void task_lectura_sensor_ina219_0x41(void *params);
void task_lectura_sensor_ina219_0x44(void *params);
void task_lectura_sensor_ina219_0x45(void *params);

#endif // _cap_sensors_h