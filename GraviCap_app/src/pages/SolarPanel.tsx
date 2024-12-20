import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React, { useEffect, useState } from 'react';
import "./CSS SolarPanel.css"

function SolarPanel () {

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
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x45') // IP de la ESP8266 (servidor) referenciado al sensor que le pedimos datos
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
      {/*header con el botón para ir hacia atrás*/}
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      {/*contenido de la pantalla*/}
      <IonContent className="ion-padding">
        <div id= "paginapanel">
          <div id= "circulopanel">
            {/*carta circular con la imagne de "panel solar"*/}
            <IonCard>
              <img src= "/Icono Panel Solar.png" alt= "Consumo" />
            </IonCard>
          </div>
          <div id= "contenedorvalores">
            {/*carta blanca contenedora de los valores y texto de voltaje y potencia*/}
            <IonCard className='cartablanca'>
              <strong><p>Valores Panel Solar</p></strong>
              <div id= "valoresconsumo">
                {/*carta morada de voltaje*/}
                <IonCard className='voltaje'>
                  Voltaje
                </IonCard> 
                {/*carta morada de potencia*/}
                <IonCard className='potencia'>
                  Potencia 
                </IonCard> 
              </div>
              <div id= "contenedorcirculos">
                <div id= "circulovoltaje">
                  {/*carta circualr contenedora del valor del voltaje de la batería*/}
                  <IonCard>
                    {/*valor de voltaje*/}
                    <strong><p> {data.voltage} V </p></strong>
                  </IonCard>
                </div>
                <div id= "circulopotencia">
                  {/*carta circular contenedora del valor de la potencia de la batería*/}
                  <IonCard>
                    {/*valor de potencia*/}
                    <strong><p> {data.potencia} W </p></strong>
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