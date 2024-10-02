import { IonApp, IonButton, IonCard, IonPage } from '@ionic/react';
import React from 'react';

function User () {
  return (
    <IonApp>
      <IonPage>
        <img src= "/GRAVICAPlogo.png" alt= "Logo GraviCap" />
        <IonCard>
          <p>Nombre:</p>
        </IonCard>
        <IonCard>
          <p>Apellido:</p>
        </IonCard>
        <IonCard>
          <p>Nombre de Usuario:</p>
        </IonCard>
        <IonCard>
          <p>Cuenta de Gmail:</p>
        </IonCard>
        <IonCard>
          <p>Fecha de Creación de Cuenta:</p>
        </IonCard>
      </IonPage>
    </IonApp>
  );
};


export default User;