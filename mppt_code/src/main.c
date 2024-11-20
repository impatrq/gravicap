#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "hardware/irq.h"

#define PWM_WRAP                        3787  // Definimos frecuencia del micro, sin prescaler, 33kHz
#define ADC_GPIO_BATTERY                26
#define ADC_IN                          27
#define ADC_CURRENT_BATTERY             28
#define ADC_CHANNEL_BATTERY             0
#define ADC_CHANNEL_IN                  1
#define ADC_CURRENT_CHANNEL_BATTERY     2

#define BATTERY_ADC_RATIO               5.5     // Habra un ratio de 5 a 1 en el voltaje leido por el ADC y la bat
#define BATTERY_IN_RATIO                14.8    

#define BULK_MAX_BATTERY_VOLTAGE        26.5
#define BULK_MAX_CURRENT_VOLTAGE        4

#define ABSORTION_MAX_BATTERY_VOLTAGE   26.5   // Umbral de tension del modo ABSORTION
#define ABSORTION_MAX_PANEL_CURRENT     4
#define ABSORTION_MIN_PANEL_CURRENT     0.2

#define FLOAT_MAX_BATTERY_VOLTAGE       25.5
#define FLOAT_MIN_BATTERY_VOLTAGE       24
#define FLOAT_MAX_CURRENT_VOLTAGE       0.6
 
#define BATTERY_MIN_VOLTAGE             23.5     

#define INTEGRAL_CONSTANT               3  

#define MAX_LINES      4
#define MAX_CHARS      20

#define PICO_DEFAULT_I2C_SDA_PIN    4
#define PICO_DEFAULT_I2C_SCL_PIN    5

float prom_minute = 0;
float prom_hour = 0;
float real_prom = 0;
int cont_minute = 0; 
int cont_hour = 0;

float battery_in = 0;
float battery_voltage = 0;
float battery_current = 0;

typedef enum {
    BULK_MODE,
    ABSORTION_MODE,
    FLOAT_MODE,
    SPIKE_MODE
} charging_mode_t;

inline static uint16_t saturador(uint16_t wrap, int16_t level);
int64_t alarm_callback(alarm_id_t id, void *user_data);
float med_volt();
float med_current();
float med_in();

int main() {
    stdio_init_all();

    sleep_ms(3000);

    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    
    uint8_t pwm = 15;
    uint8_t slice = pwm_gpio_to_slice_num(pwm);
    int16_t pwm_level = PWM_WRAP / 2;

    // Se define el modo inicial como BULK
    charging_mode_t charging_mode = BULK_MODE;

    // Inicializacion del ADC
    adc_init();
    adc_gpio_init(ADC_GPIO_BATTERY);
    adc_gpio_init(ADC_CURRENT_BATTERY);
    adc_select_input(ADC_CHANNEL_BATTERY);

    // Habilito GPIO como salida de PWM
    gpio_set_function(pwm, GPIO_FUNC_PWM);

    // Wrap para 33 KHz de PWM a 125 MHz de clock
    pwm_set_wrap(slice, PWM_WRAP);

    // 50% de ancho de pulso de partida
    pwm_set_gpio_level(pwm, pwm_level);

    // Habilitar PWM
    pwm_set_enabled(slice, true);

    add_alarm_in_ms(-1000, alarm_callback, NULL, false);

    while (true) {
        // Selecciono el canal de la tension y se lee y se convierte
        adc_select_input(ADC_CHANNEL_BATTERY);
        battery_voltage = med_volt();

        // Selecciono el canal de la corriente y se lee y se convierte
        adc_select_input(ADC_CURRENT_CHANNEL_BATTERY);
        battery_current = med_current();

        // Selecciono el canal de la entrada de tension, se lee y se convierte
        adc_select_input(ADC_CHANNEL_IN);
        battery_in = med_in();

        if (charging_mode == BULK_MODE){
            if (battery_voltage > BULK_MAX_BATTERY_VOLTAGE) {
                    // Cambio modo de carga en caso de que corriente baje del umbral
                    charging_mode = ABSORTION_MODE;
                }
            else {
                printf("BULK\n");
            }
        }
        if (charging_mode == ABSORTION_MODE){
            if (battery_current < ABSORTION_MIN_PANEL_CURRENT) {
                    // Cambio modo de carga en caso de que corriente baje del umbral
                    charging_mode = FLOAT_MODE;
                }
            else{
                printf("ABSORTION\n");
            }
        }
        if (charging_mode == FLOAT_MODE){
            if (battery_voltage < FLOAT_MIN_BATTERY_VOLTAGE) {
                    charging_mode = BULK_MODE;
                }  
            if (battery_current > FLOAT_MAX_CURRENT_VOLTAGE) {
                    // Cambio modo de carga en caso de que corriente exceda umbral
                    charging_mode = BULK_MODE;
                }
            else{
                printf("FLOAT\n");
            }
        }
    ///////////////   END MDOE VERIFICATION   ///////////////   
    
    ///////////////   BULK   ///////////////
        if (charging_mode == BULK_MODE) {
            float error = (BULK_MAX_CURRENT_VOLTAGE - battery_current) * 25;
            if (battery_current > BULK_MAX_CURRENT_VOLTAGE) {
                pwm_level = pwm_level - (-1 * error * INTEGRAL_CONSTANT);
            }
            else {
                pwm_level += 1 * error * INTEGRAL_CONSTANT;
            }
            // Verifico que no exceda los limites
            pwm_level = saturador(PWM_WRAP, pwm_level);
            // Ajusto PWM
            pwm_set_gpio_level(pwm, pwm_level);
        }
    ///////////////   END BULK   ///////////////
    
    ///////////////   ABSORTION   ///////////////
        if (charging_mode == ABSORTION_MODE)  {
            float errorv = (ABSORTION_MAX_BATTERY_VOLTAGE - battery_voltage) * 6.849315;
            float errorc = (ABSORTION_MAX_PANEL_CURRENT - battery_current) * 25;
            if(battery_current > ABSORTION_MAX_PANEL_CURRENT) {
                pwm_level = pwm_level - (-1 * errorc * INTEGRAL_CONSTANT);
            }  
            else if(battery_voltage > ABSORTION_MAX_BATTERY_VOLTAGE) {
                // Incremento el duty en una unidad
                pwm_level += 1 * errorv * INTEGRAL_CONSTANT;
            }
            else {
                pwm_level = pwm_level - (-1 * errorv * INTEGRAL_CONSTANT);
            }
            // Verifico que no exceda los limites
            pwm_level = saturador(PWM_WRAP, pwm_level);
            // Ajusto PWM
            pwm_set_gpio_level(pwm, pwm_level);
        }
    ///////////////  END ABSORTION  ////////////////

    ///////////////  FLOAT  ////////////////
        if(charging_mode == FLOAT_MODE) {
            float error = (FLOAT_MAX_BATTERY_VOLTAGE - battery_voltage) * 7.24638;
            if (battery_voltage > FLOAT_MAX_BATTERY_VOLTAGE){
                pwm_level = pwm_level - (-1 * error * INTEGRAL_CONSTANT);
            }
            else {
                pwm_level += 1 * error * INTEGRAL_CONSTANT;
            }
            // Verifico que no exceda los limites
            pwm_level = saturador(PWM_WRAP, pwm_level);
            // Ajusto PWM
            pwm_set_gpio_level(pwm, pwm_level);
        }
    ///////////////  END FLOAT  ////////////////
        printf("final, %f\n", pwm_level * 0.0264061262);
    }
    return 0;
}



// Saturador basico, se asegura que el PWM no sea ni negativo ni que se exceda del wrap
inline static uint16_t saturador(uint16_t wrap, int16_t level) {
    if(level > PWM_WRAP) {
        level = PWM_WRAP;
        return PWM_WRAP;
    }
    else if(level < 0) {
        level = 0;
        return 0;
    }
    return level;
}

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    if(cont_minute < 60){
        prom_minute += (battery_in * battery_current);
        cont_minute += 1;
    }
    else{
        prom_hour += (prom_minute / cont_minute);
        cont_hour += 1;
        cont_minute = 0;
    }
    return 0;
}

float med_volt(){
    float prom = 0;
    for (int i = 0; i < 10; i++){
        float volt = BATTERY_ADC_RATIO * adc_read() * 3.3 / (1 << 12);
        prom = prom + volt;
        }
    return prom/10;
}

float med_current(){
    float prom = 0;
    for (int i = 0; i < 10; i++){
        float current = ((adc_read() * 3.3 / (1 << 12)) - 2.565) * (-10);
        prom = prom + current;
    }
    return prom/10;
}

float med_in(){
    float prom = 0;
    for (int i = 0; i < 10; i++){
        float volt = BATTERY_IN_RATIO * adc_read() * 3.3 / (1 << 12);
        prom = prom + volt;
    }
    if (prom < 5){
        prom = 0;
    }
    return prom/10;
}
