import { IonCard, IonHeader, IonToolbar, IonButtons, IonBackButton, IonContent} from '@ionic/react';
import { } from 'ionicons/icons';
import "./CSS ChargingPowerGraphics.css"
import React from 'react';
import LineChart from './LineChartCharging';

function Charging () {
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
        <div id= "contenidocarga">
          <IonCard>
            <LineChart></LineChart>
          </IonCard>
        </div>
      </IonContent>
    </>
	)
}

export default Charging;