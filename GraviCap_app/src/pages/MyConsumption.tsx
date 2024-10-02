import { IonApp, IonBackButton, IonButton, IonDatetime, IonButtons, IonCard, IonHeader, IonPage, IonTitle, IonToolbar, IonContent } from '@ionic/react';
import React from 'react';

function MyConsumption () {
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
        <IonCard> <img src= "/Icono Consumo.png" alt= "Consumo" /> </IonCard> {/*lo redondeo y pongo el logo de consumo*/}
        <IonCard> <p>Su consumo es</p></IonCard>
        <IonCard> <p>valor del consumo del usuario</p></IonCard> {/*lo redondeo y pongo el valor del consumo del usuario*/}
        <IonDatetime></IonDatetime>
      </IonContent>
    </>
	)
}

export default MyConsumption; 