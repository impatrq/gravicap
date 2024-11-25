import { IonApp, IonButton, IonCard, IonContent, IonIcon, IonLabel, IonNavLink, IonPage } from '@ionic/react';
import { } from 'ionicons/icons';
import React from 'react';
import "./CSS GraphicsPage.css"
import Discharge from './DischargePowerGraphic';
import Start from './StartPage';
import Charging from './ChargingPowerGraphic';

function Graphics () {
  return (
    <IonApp>
      <IonPage>
        {/*contenido de la página*/}
        <IonContent className="ion-padding">
          <div id= "paginagraficos">
            <div id= "cartaarriba">
              {/*carta contenedora de la imagen superior central de esquema de potencias*/}
              <IonCard>
                {/*imagen y texto de la carta de esquemas de potencia*/}
                <img src= "/graficolineas.png" alt= "Esquema de Potencias"/>
                <strong>Esquemas de Potencias</strong>
              </IonCard>
            </div>
            <div id= "contenedorcentral">
              <div id= "cartaboton">
              {/*ruta declarada para ir hacia la pantalla de gráfico de potencia de carga*/}
              <IonNavLink routerDirection="forward" component={() => <Charging />}>
                {/*carta contenedora del botón de potencia de carga*/}
                <IonCard>
                  <div id= "cartamedio"> 
                    {/*texto e imagen dentro de la carta*/}
                    <strong>Potencia de Carga</strong>
                    <img src= "/graficoascendente.png" alt= "Esquema de Potencias"/>
                  </div>
                </IonCard>
              </IonNavLink>
              </div>
              <div id= "cartaboton1">
                {/*ruta declarada para ir hacia la pantalla de gráfcio de potencia de descarga*/}
                <IonNavLink routerDirection="forward" component={() => <Discharge />}>
                  {/*carta contenedora del botón de potencai de descarga*/}
                  <IonCard>
                    <div id= "cartaabajo">
                      {/*texto e imagen dentro de la carta*/}
                      <strong>Potencia de Descarga</strong>
                      <img src= "/descendente.png" alt= "Esquema de Potencias"/>
                    </div>
                  </IonCard>
                </IonNavLink>
              </div>
              {/*ruta declarada para ir hacai la página de inicio*/}
              <IonNavLink routerDirection="forward" component={() => <Start />}>
                {/*botón de tamaño pequeño*/}
                <IonButton size="small">
                  Página de Inicio
                </IonButton>
              </IonNavLink>
            </div>
          </div>
        </IonContent>
      </IonPage>
    </IonApp>
  );
};

export default Graphics;