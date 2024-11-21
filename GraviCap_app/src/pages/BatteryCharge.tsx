import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS BatteryCharge.css"

function BatteryCharge () {

  const [data, setData] = useState({
    carga: null,
    nombre: '',
    corriente: null,
    voltage: null,
    potencia: null
  });

  useEffect(() => {
    // Realizamos el fetch para obtener los datos
    fetch('http://192.168.124.79/sensor?nombre=Sensor_0x40') // Cambia la URL a la IP del ESP8266
      .then((response) => response.json())
      .then((data) => {
        // Actualizamos el estado con los valores recibidos
        setData({
          carga: data.carga,
          nombre: data.nombre,
          corriente: data.corriente,
          voltage: data.voltage,
          potencia: data.potencia
        });
      })
      .catch((error) => {
        console.error('Error al obtener los datos:', error);
      });
  }, []); // El array vacío asegura que solo se ejecute una vez al montar el componente

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
                    <strong><p>{data.carga} % </p></strong>
                  </IonCard>
                </div>
              </IonCard>
            </div>
          </div>
          <div id= "textocarga">
            <div id= "valorcarga">
              {/*valor del tiempo de carga total de la batería*/}
              <p>10 minutos</p>
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