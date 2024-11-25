import React, { useEffect, useState } from 'react';
import { IonApp, IonAvatar, IonButton, IonButtons, IonCard, IonContent, IonHeader, IonItem, IonMenu, IonMenuButton, IonNavLink, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import "./CSS StartPage.css"
import GeneratedEnergy from './GeneratedEnergy';
import BatteryCharge from './BatteryCharge';
import BatteryValues from './BatteryValues';
import MyConsumption from './MyConsumption';
import SolarPanel from './SolarPanel';
import Graphics from './GraphicsPage';

function Start () {

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
      fetch('http://192.168.124.160/sensor?nombre=Sensor_0x44') // Cambia la URL a la IP del ESP8266
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
		<IonApp>
      {/*menú en la parte superior derecha*/}
      <IonMenu side="end" contentId="contenido">
        <IonHeader>
          <IonToolbar>
            <IonTitle>Nuestras Redes</IonTitle>
          </IonToolbar>
        </IonHeader>
        {/*contenido del menú al abrirlo*/}
        <IonContent className="ion-padding">
          <div id= "textoredes">
            {/*links hacia nuestras redes*/}
            <p><a target="_blank" rel="noopener noreferrer" href="https://www.instagram.com/gravi.cap/">Instagram</a></p>
            <p><a target="_blank" rel="noopener noreferrer" href="https://gravicap.vercel.app/home">Página Web</a></p>
            <p><a target="_blank" rel="noopener noreferrer" href="https://github.com/impatrq/gravicap">Github</a></p>
            <p>Mail de Contacto: gravicap.arg@gmail.com</p>
          </div>
        </IonContent>
      </IonMenu>
      {/*contenido principal del archivo*/}
      <IonPage id="contenido">
        {/*barra de herramientas superior central*/}
        <IonToolbar>
          <IonItem>
            {/*icono de gravicap en la parte superior izquierda*/}
            <IonAvatar slot="start">
              <img alt="Foto de Usuario" src="GRAVICAPlogo.png" />
            </IonAvatar>
            {/*texto de la barra*/}
            <p>Hola, Usuario de GraviCap</p> 
          </IonItem>
          {/*botón de menu en la parte superior derecha*/}
          <IonButtons slot="end">
            <IonMenuButton></IonMenuButton>
          </IonButtons>
        </IonToolbar>
        {/*contenido central de la pantalla*/}
        <IonContent className="ion-padding">
          <div id= "inicio">
            {/*ruta de navegación hacia la pantalla de energia generada*/}
            <IonNavLink routerDirection="forward" component={() => <GeneratedEnergy />}>
              {/*carta de energía genrada*/}
              <IonCard>
                {/*imagen y texto de energia generada*/}
                <img src= "Aroicono.png" alt= "Arco Energia Generada"></img>
                <p>Energía Generada</p>
              </IonCard>
            </IonNavLink>
            {/*ruta de navegación hacia carga de batería*/}
            <IonNavLink routerDirection="forward" component={() => <BatteryCharge />}> 
              {/*carta de carga de batería*/}
              <IonCard>
                <div id= "contenedoreb">
                  <div id= "circuloporcentaje">
                    <div id= "circuloatras">
                      {/*circulo de carga porcentual*/}
                      <IonCard>
                        <div id= "circuloadelante">
                          <IonCard>
                            <strong><p> {data.carga} %</p></strong>
                          </IonCard>
                        </div>
                      </IonCard>
                    </div>
                  </div>
                  <div id= "imagenbateria">
                    {/*imagen de la batería con el logo de gravicap*/}
                    <img src= "Bateríasexo.png" alt= "Logo Batería"/>
                  </div>
                </div>
                {/*texto en la parte inferior central de la carta*/}
                <p>Carga de Batería</p>
              </IonCard>
            </IonNavLink>
            {/*carta en la parte inferior central con las tres cartas de mi consumo, panel solar y valores de batería*/}
            <IonCard>
              <div id= "contenedorde3">
                <div id= "consumo">
                  {/*ruta de navegación hacia mi consumo*/}
                  <IonNavLink routerDirection="forward" component={() => <MyConsumption />}> 
                    {/*carta circular de mi consumo*/}
                    <IonCard>
                      {/*imagen tipo icono de mi consumo*/}
                      <img src= "Icono Consumo.png" alt= "Consumo"/>
                    </IonCard>
                    {/*texto de la carta en la parte inferior*/}
                    <p>Mi Consumo</p>
                  </IonNavLink>
                </div>
                <div id= "panelsolar">
                  {/*ruta de navegación hacia la pantalla de panel solar*/}
                  <IonNavLink routerDirection="forward" component={() => <SolarPanel />}> 
                    {/*carta circular de panel solar*/}
                    <IonCard>
                      {/*imagen tipo icono de panel solar*/}
                      <img src= "Icono Panel Solar.png" alt= "PanelSolar"/>
                    </IonCard>
                    {/*texto de la carta ubicado en la parte inferior*/}
                    <p>Panel Solar</p>
                  </IonNavLink>
                </div>
                <div id= "valoresbateria">
                  {/*ruta de navegación hacia la pantalla de valores de batería*/}
                  <IonNavLink routerDirection="forward" component={() => <BatteryValues />}> 
                    {/*carta circular de valores de batería*/}
                    <IonCard>
                      {/*imagen tipo icono de grafico de columnas*/}
                      <img src= "IconoGraficoColumnas.png" alt= "Grafico tipo Columnas"/>
                    </IonCard>
                    {/*texto de la carta ubicado en la parte inferior*/}
                    <p>Valores Batería</p>
                  </IonNavLink>
                </div>
              </div>
            </IonCard>
            {/*ruta de navegación hacia la pantalla de graficos de potencia*/}
            <IonNavLink routerDirection="forward" component={() => <Graphics />}>
              {/*boton para ir hacia la pantalla de graficos*/}
              <IonButton size="small">
                Página de Gráficos
              </IonButton>
            </IonNavLink>
          </div>
        </IonContent>
      </IonPage>
		</IonApp>
	);
}

export default Start;