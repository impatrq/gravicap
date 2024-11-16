# Etapa de Control

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;La etapa de control es la encargada de sensar en __Tiempo Real__ distintos parámetros asociados al funcionamiento del sistema.
Una vez recolectados, los procesa para controlar el dispositivo y enviarlos a un [servidor web](https://github.com/impatrq/gravicap/tree/main/Servidor_Web).<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El sistema es ejecutado por un microcontrolador [RP2040-Zero](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf).<br>

## Recursos utilizados
- [FreeRTOS](https://www.freertos.org/)
- [Pico-SDK](https://github.com/raspberrypi/pico-sdk/tree/master)
- [Multicore en RP2040](https://github.com/raspberrypi/pico-sdk/tree/master/src/rp2_common/pico_multicore) 
   
## Componentes utilizados
- [INA219](https://www.ti.com/lit/ds/symlink/ina219.pdf)  
- [Encoder Rotativo Incremental](https://en.wikipedia.org/wiki/Rotary_encoder)
- [ESP8266-01](https://www.espressif.com/sites/default/files/documentation/esp8266-technical_reference_en.pdf)

## Lenguaje utilizado  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C (con soporte de [PlatformIO](https://docs.platformio.org/en/latest/)).
    
## Tipos de comunicación serial  
- __UART__: En el intercambio de información con la [ESP8266-01](https://www.espressif.com/sites/default/files/documentation/esp8266-technical_reference_en.pdf).
- __I2C__: Usado para recibir la entrega de datos de los [INA219](https://www.ti.com/lit/ds/symlink/ina219.pdf), recibe datos en simultáneo desde 4 sensores. 
