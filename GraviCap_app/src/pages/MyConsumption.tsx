import { IonApp, IonBackButton, IonButton, IonDatetime, IonButtons, IonCard, IonHeader, IonPage, IonTitle, IonToolbar, IonContent } from '@ionic/react';
import React from 'react';
import "./CSS MyConsumption.css"

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
        <div id= "paginaconsumo">
          <div id= "circuloconsumo">
            <IonCard> 
              <img src= "/Icono Consumo.png" alt= "Consumo" />
            </IonCard> 
          </div>
          <div id= "valorredondeado">
            <IonCard> 
              <strong><p>Su Consumo es</p></strong>
              <div id= "valorconsumo">
                <IonCard>
                  <strong><p>5W</p></strong>
                </IonCard>
              </div>
            </IonCard> 
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default MyConsumption; 