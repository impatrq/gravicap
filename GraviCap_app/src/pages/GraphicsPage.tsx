import { IonApp, IonButton, IonCard, IonIcon, IonLabel, IonPage } from '@ionic/react';
import { } from 'ionicons/icons';
import React from 'react';

function Graphics () {
  return (
    <IonApp>
      <IonPage>
        <img src= "/GRAVICAPlogo.png" alt= "Esquema de Potencias" />
        <IonCard> {/*linkear con la pantalla de grafico de carga*/}
          <IonLabel>Potencia de Carga</IonLabel>
          <IonIcon />
        </IonCard>

        <IonCard> {/*linkear con la pantalla de grafico de descarga*/}
          <IonLabel>Potencia de Descarga</IonLabel>
          <IonIcon />
        </IonCard>
      </IonPage>
    </IonApp>
  );
};

export default Graphics;