# MPPT - Maximun Power Point Tracking
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El MPPT es una técnica utilizada en cargadores para obtener la máxima potencia posible cuando las condiciones de alimentación son inestables en el tiempo.<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Esta tecnología es aprovechada por una de las etapas del dispositivo, la que se asegura de convertir de forma óptima la energía entregada por el panel solar 
u otros generadores de energía utilizados. La etapa está conformada por un [circuito electrónico](https://github.com/impatrq/gravicap/tree/main/PCB/MPPT).<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El circuito incluye un microcontrolador [RP2040-Zero](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf), allí corre el programa presente en este directorio.<br>

## Recursos utilizados
- Lenguaje C (con soporte de [PlatformIO](https://docs.platformio.org/en/latest/))
- Comunicación serial I2C
- Converción Analógico Digital [ADC](https://github.com/raspberrypi/pico-sdk/tree/master/src/rp2_common/hardware_adc)
- [Pico-SDK](https://github.com/raspberrypi/pico-sdk/tree/master)
