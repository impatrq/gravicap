import { IonApp, IonBackButton, IonButton, IonButtons, IonCard, IonContent, IonDatetime, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import React from 'react';

function SolarPanel () {
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
        <IonCard><img src= "/Icono Panel Solar.png" alt= "Consumo" /></IonCard>
          {/*carta para los valores de voltaje y potencia del panel solar*/}
          <IonCard>
            <p>Valores del Panel Solar</p> {/*Poner los valores en sus deternminadas cartas sacando los valores de la base de datos*/}
            <IonCard> Voltaje </IonCard> 
            <IonCard> Potencia </IonCard> 
            <IonDatetime></IonDatetime>
          </IonCard>
      </IonContent>
    </>
	)
}

export default SolarPanel; 