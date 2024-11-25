import {IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS BatteryValues.css"
import BarChart from './GraphicValues';

function BatteryValues () {

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
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x44') // IP de la ESP8266 (servidor)
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
        <div id= "paginavaloresbateria">
          <IonCard>
            <BarChart></BarChart>
          </IonCard>
          <div id="carta">
            <IonCard>
              <div id= "contenedor3valores">
                <div id= "voltajecolumna">
                  <IonCard>
                    <strong> {data.voltage} V </strong>
                  </IonCard>
                </div>
                <div id= "corrientecolumna">
                  <IonCard>
                    <strong> {data.corriente} A </strong>
                  </IonCard>
                </div>
                <div id= "potenciacolumna">
                  <IonCard>
                    <strong> {data.potencia} W </strong>
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

export default BatteryValues;