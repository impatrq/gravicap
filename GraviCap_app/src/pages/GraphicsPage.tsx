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
        <IonContent className="ion-padding">
          <div id= "paginagraficos">
            <div id= "cartaarriba">
              <IonCard>
                <img src= "/graficolineas.png" alt= "Esquema de Potencias"/>
                <strong>Esquemas de Potencias</strong>
              </IonCard>
            </div>
            <div id= "cartaboton">
            <IonNavLink routerDirection="forward" component={() => <Charging />}>
              <IonCard>
                <div id= "cartamedio"> 
                  <strong>Potencia de Carga</strong>
                  <img src= "/graficoascendente.png" alt= "Esquema de Potencias"/>
                </div>
              </IonCard>
            </IonNavLink>
            </div>
            <div id= "cartaboton1">
              <IonNavLink routerDirection="forward" component={() => <Discharge />}>
                <IonCard>
                  <div id= "cartaabajo">
                    <strong>Potencia de Descarga</strong>
                    <img src= "/descendente.png" alt= "Esquema de Potencias"/>
                  </div>
                </IonCard>
              </IonNavLink>
            </div>
            <IonNavLink routerDirection="forward" component={() => <Start />}>
              <IonButton size="small">
                Página de Inicio
              </IonButton>
            </IonNavLink>
          </div>
        </IonContent>
      </IonPage>
    </IonApp>
  );
};

export default Graphics;