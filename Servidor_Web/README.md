# Servidor Web

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Este servidor recibe datos actualizados vía __UART__ desde la [RP2040-Zero](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf), 
los datos luego serán levantados por la [aplicación móvil](https://github.com/impatrq/gravicap/tree/main/GraviCap_app), un punto de acceso directo a la información del dispositivo en __Tiempo Real__ para el usuario.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El programa del servidor es ejecutado por una [ESP8266-01](https://www.espressif.com/sites/default/files/documentation/esp8266-technical_reference_en.pdf).<br>
#### Lenguaje utilizado
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C++ (con soporte de [PlatformIO](https://docs.platformio.org/en/latest/)).<br>
