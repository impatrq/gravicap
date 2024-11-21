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
                    <strong>{data.voltage} V </strong>
                  </IonCard>
                </div>
                <div id= "corrientecolumna">
                  <IonCard>
                    <strong>{data.corriente} A </strong>
                  </IonCard>
                </div>
                <div id= "potenciacolumna">
                  <IonCard>
                    <strong>{data.potencia} W </strong>
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