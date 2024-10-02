import { IonApp, IonBackButton, IonButton, IonButtons, IonCard, IonContent, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import React from 'react';

function BatteryCharge () {
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
        <IonCard>
          {/*colocar grafico del porcentaje de carga de la batería*/}
        </IonCard>
        <p>*sacar valor de la base de datos del tiempo de carga* para completar la carga</p>
      </IonContent>
    </>
	)
}

export default BatteryCharge;