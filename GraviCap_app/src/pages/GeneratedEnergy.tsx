import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS GeneratedEnergy.css"
import CircularChart from './CircularGraphic';

function GeneratedEnergy () {

  const [data, setData] = useState({
    carga: null,
    nombre: '',
    corriente: null,
    voltage: null,
    potencia: null
  });

  useEffect(() => {
    // Realizamos el fetch para obtener los datos
    fetch('http://192.168.124.79/sensor?nombre=Sensor_0x44') // Cambia la URL a la IP del ESP8266
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
        <div id= "paginaenergiagenerada">
          {/*decalro el componente de carta circular con el valor de variación de la energía*/}
          <CircularChart value={3.5}></CircularChart>
          <br></br>
          <div id= "contenedorenergia">
            {/*carta circular para referenciar el valor con el color en el grafico*/}
            <IonCard></IonCard>
            {/*texto de energía generada*/}
            <strong>Energía Generada</strong>
            <div id= "valorpotenciaeg">
              {/*valor de potencia de energía generada en referencai con el valor del grafico*/}
              <strong>5W</strong>
            </div> 
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default GeneratedEnergy;