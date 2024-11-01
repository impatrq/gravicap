import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React from 'react';
import "./CSS SolarPanel.css"

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
        <div id= "paginapanel">
          <div id= "circulopanel">
            <IonCard>
              <img src= "/Icono Panel Solar.png" alt= "Consumo" />
            </IonCard>
          </div>
          <div id= "contenedorvalores">
            <IonCard className='cartablanca'>
              <strong><p>Valores Panel Solar</p></strong>
              <div id= "valoresconsumo">
                <IonCard className='voltaje'>
                  Voltaje
                </IonCard> 
                <IonCard className='potencia'>
                  Potencia 
                </IonCard> 
              </div>
              <div id= "contenedorcirculos">
                <div id= "circulovoltaje">
                  <IonCard>
                    <strong><p>24V</p></strong>
                  </IonCard>
                </div>
                <div id= "circulopotencia">
                  <IonCard>
                    <strong><p>30W</p></strong>
                  </IonCard>
                </div>
              </div>
            </IonCard>
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default SolarPanel; 