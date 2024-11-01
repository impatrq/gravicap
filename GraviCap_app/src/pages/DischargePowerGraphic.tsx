import { IonApp, IonButton, IonCard, IonIcon, IonLabel, IonDatetime, IonHeader, IonToolbar, IonButtons, IonBackButton, IonContent } from '@ionic/react';
import { } from 'ionicons/icons';
import React from 'react';
import "./CSS DischargePowerGraphic.css"
import LineChart1 from './LineChartDischarge';

function Discharge () {
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
        <div id= "contenidodescarga">
          <IonCard>
            <LineChart1></LineChart1>
          </IonCard>
        </div>
      </IonContent>
    </>
	)
}

export default Discharge;