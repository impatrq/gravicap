import { IonApp, IonButton, IonCard, IonIcon, IonLabel, IonDatetime, IonHeader, IonToolbar, IonButtons, IonBackButton, IonContent } from '@ionic/react';
import { } from 'ionicons/icons';
import React from 'react';
import "./CSS DischargePowerGraphic.css"
import LineChart1 from './LineChartDischarge';

function Discharge () {
  return (
    <>
      {/*barra de header con botón para ir hacia atrás*/}
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      {/*contenido de la pantalla*/}
      <IonContent className="ion-padding">
        <div id= "contenidodescarga">
          {/*carta contenderora del gráfcio de línea*/}
          <IonCard>
            {/*declaro el gráfcio de línea que está desarrollado en otro archivo*/}
            <LineChart1></LineChart1>
          </IonCard>
        </div>
      </IonContent>
    </>
	)
}

export default Discharge;