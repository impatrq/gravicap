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
    potencia: null,
  });
  
  useEffect(() => {
    // Función para obtener datos
    const fetchData = () => {
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x41') // IP de la ESP8266 (servidor)
        .then((response) => response.json())
        .then((data) => {
          setData({
            carga: data.carga,
            nombre: data.nombre,
            corriente: data.corriente,
            voltage: data.voltage,
            potencia: data.potencia,
          });
          console.log('Datos actualizados:', data); // Log para verificar los valores
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
        <div id= "paginaenergiagenerada">
          {/*declaro el gráffico circular con el valor de variación de la energía*/}
          <CircularChart value={data.potencia}></CircularChart>
          <br></br>
          <div id= "contenedorenergia">
            {/*carta circular para referenciar el valor con el color en el grafico*/}
            <IonCard></IonCard>
            {/*texto de energía generada*/}
            <strong>Energía Generada</strong>
            <div id= "valorpotenciaeg">
              {/*valor de potencia de energía generada en referencia con el valor del gráfico*/}
              <strong> {data.potencia} W </strong>
            </div> 
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default GeneratedEnergy;