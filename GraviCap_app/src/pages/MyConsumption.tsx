import { IonApp, IonBackButton, IonButton, IonDatetime, IonButtons, IonCard, IonHeader, IonPage, IonTitle, IonToolbar, IonContent } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS MyConsumption.css"

function MyConsumption () {

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
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x40') // Cambia la URL a la IP del ESP8266
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
                  <strong><p> {data.potencia} W</p></strong>
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