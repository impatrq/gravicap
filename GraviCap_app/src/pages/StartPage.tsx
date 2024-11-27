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

  const [carga, setCarga] = useState(null); // Estado para la carga del sensor 44
    const [potencia, setPotencia] = useState(null); // Estado para la potencia del sensor 41
    useEffect(() => {
        // Función para obtener los datos del sensor 44
        const fetchSensor44 = () => {
            fetch('http://192.168.124.160/sensor?nombre=Sensor_0x44') // IP referenciado al sensor 44
                .then((response) => response.json())
                .then((data) => {
                    setCarga(data.carga); // Actualiza la carga del sensor 44
                    console.log('Carga del Sensor 0x44:', data.carga);
                })
                .catch((error) => {
                    console.error('Error al obtener la carga del sensor 44:', error);
                });
        };
        // Función para obtener los datos del sensor 41
        const fetchSensor41 = () => {
            fetch('http://192.168.124.160/sensor?nombre=Sensor_0x41') // IP referenciado al sensor 41
                .then((response) => response.json())
                .then((data) => {
                    setPotencia(data.potencia); // Actualiza la potencia del sensor 41
                    console.log('Potencia del Sensor 0x41:', data.potencia);
                })
                .catch((error) => {
                    console.error('Error al obtener la potencia del sensor 41:', error);
                });
        };
        // Llamamos a ambas funciones al montar el componente
        fetchSensor44();
        fetchSensor41();
        // Configuramos el intervalo para actualizar los datos de ambos sensores cada 2 segundos
        const interval = setInterval(() => {
            fetchSensor44();
            fetchSensor41();
        }, 2000);

        // Limpiamos el intervalo al desmontar el componente
        return () => clearInterval(interval);
    }, []); // Ejecuta solo una vez al montar el componente

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
                <strong><p>{potencia} W </p></strong>
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
                            {/*valor de la carga de la batería*/}
                            <strong><p> {carga} % </p></strong>
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
              {/*boton para ir hacia la página de graficos*/}
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