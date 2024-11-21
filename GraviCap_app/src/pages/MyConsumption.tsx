import { IonApp, IonBackButton, IonButton, IonDatetime, IonButtons, IonCard, IonHeader, IonPage, IonTitle, IonToolbar, IonContent } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS MyConsumption.css"

function MyConsumption () {

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
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>

      <IonContent className="ion-padding">
        <div id= "paginaconsumo">
          <div id= "circuloconsumo">
            <IonCard> 
              <img src= "/Icono Consumo.png" alt= "Consumo" />
            </IonCard> 
          </div>
          <div id= "valorredondeado">
            <IonCard> 
              <strong><p>Su Consumo es</p></strong>
              <div id= "valorconsumo">
                <IonCard>
                  <strong><p>{data.potencia} W </p></strong>
                </IonCard>
              </div>
            </IonCard> 
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default MyConsumption; 