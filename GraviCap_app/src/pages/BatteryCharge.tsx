import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS BatteryCharge.css"

function BatteryCharge () {

  const [data, setData] = useState({
    carga: null,
    nombre: '',
    corriente: null,
    voltage: null,
    potencia: null,
  });
  const [tiempoRestante, setTiempoRestante] = useState(0); // Estado para el tiempo restante
  const tiempoTotalCarga = 60; // Tiempo total de carga en minutos (puedes ajustarlo)

  useEffect(() => {
    // Función para obtener y procesar los datos
    const fetchData = () => {
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x44') // Cambia la URL a la IP del ESP8266
        .then((response) => response.json())
        .then((data) => {
          // Actualizamos el estado con los valores recibidos
          setData({
            carga: data.carga,
            nombre: data.nombre,
            corriente: data.corriente,
            voltage: data.voltage,
            potencia: data.potencia,
          });

          // Calculamos el tiempo restante con base en la carga recibida
          const porcentajeCarga = parseFloat(data.carga); // Parsear el porcentaje de carga
          const tiempoTranscurrido = (porcentajeCarga / 100) * tiempoTotalCarga;
          const tiempoFaltante = tiempoTotalCarga - tiempoTranscurrido;
          setTiempoRestante(tiempoFaltante);
        })
        .catch((error) => {
          console.error('Error al obtener los datos:', error);
        });
    };

    // Llamamos a fetchData al montar el componente
    fetchData();

    // Configuramos el intervalo para actualizar los datos cada 2 segundos
    const interval = setInterval(fetchData, 2000);

    // Limpiamos el intervalo al desmontar el componente
    return () => clearInterval(interval);
  }, []); // El array vacío asegura que solo se configure el intervalo una vez

  return (
    <>
      {/*header principal de la pantalla*/}
      <IonHeader>
        {/*barra de herramientas superior*/}
        <IonToolbar>
          {/*botón ubicado en la parte de inico, en la iaquierda de la barra*/}
          <IonButtons slot="start">
            {/*botón para volver hacia la pantalla anterior*/}
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      {/*contenido central de la pantalla*/}
      <IonContent className="ion-padding">
        <div id= "paginabateria">
          <div id= "total">
            <div id= "atras">
              {/*carta circular trasera*/}
              <IonCard>
                <div id= "adelante">
                  {/*carta circular delantera contendora del valor porcentaul de la carga de batería*/}
                  <IonCard>
                    {/*valor porcentual de la carga de la batería*/}
                    <strong><p> {data.carga} % </p></strong>
                  </IonCard>
                </div>
              </IonCard>
            </div>
          </div>
          <div id= "textocarga">
            <div id= "valorcarga">
              {/*valor del tiempo de carga total de la batería*/}
              <p> {tiempoRestante.toFixed(2)} minutos </p>
            </div>
            <div id= "textoabajo">
              {/*texto del tiempo de carga*/}
              <p>para completar la carga</p>
            </div>
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default BatteryCharge;