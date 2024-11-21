import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS SolarPanel.css"

function SolarPanel () {

  const [data, setData] = useState({
    carga: null,
    nombre: '',
    corriente: null,
    voltage: null,
    potencia: null
  });

  useEffect(() => {
    // Realizamos el fetch para obtener los datos
    fetch('http://192.168.124.79/sensor?nombre=Sensor_0x45') // Cambia la URL a la IP del ESP8266
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
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
        <div id= "paginapanel">
          <div id= "circulopanel">
            <IonCard>
              <img src= "/Icono Panel Solar.png" alt= "Consumo" />
            </IonCard>
          </div>
          <div id= "contenedorvalores">
            <IonCard className='cartablanca'>
              <strong><p>Valores Panel Solar</p></strong>
              <div id= "valoresconsumo">
                <IonCard className='voltaje'>
                  Voltaje
                </IonCard> 
                <IonCard className='potencia'>
                  Potencia 
                </IonCard> 
              </div>
              <div id= "contenedorcirculos">
                <div id= "circulovoltaje">
                  <IonCard>
                    <strong><p>{data.voltage} V </p></strong>
                  </IonCard>
                </div>
                <div id= "circulopotencia">
                  <IonCard>
                    <strong><p>{data.potencia} W </p></strong>
                  </IonCard>
                </div>
              </div>
            </IonCard>
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default SolarPanel; 