import { IonApp, IonBackButton, IonButton, IonButtons, IonCard, IonContent, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import React from 'react';

function GeneratedEnergy () {
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
          {/*acá tengo que poner el grafico interactivo de energía generada. Grafico de cuanto valor de potencia está entregando*/}
          <img src= "/GRAVICAPlogo.png" alt= "Energía Generada" />
          <br></br>
          <p> Energía generada: x W</p>
      </IonContent>
    </>
	)
}

export default GeneratedEnergy;