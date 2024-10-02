import React from 'react';
import { IonApp, IonAvatar, IonBackButton, IonButton, IonButtons, IonCard, IonCardContent, IonCardHeader, IonCardSubtitle, IonCardTitle, IonContent, IonHeader, IonItem, IonLabel, IonMenu, IonMenuButton, IonNavLink, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import "./CSS StartPage.css"
import Tabs from '../components/Tabs';
import GeneratedEnergy from './GeneratedEnergy';
import BatteryCharge from './BatteryCharge';
import BatteryValues from './BatteryValues';
import MyConsumption from './MyConsumption';
import SolarPanel from './SolarPanel';

function Start () {
	return (
		<IonApp>
      <IonMenu side="end" contentId="contenido">
        <IonHeader>
          <IonToolbar>
            <IonTitle>Cosas GraviCap</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonContent className="ion-padding">
          Links GraviCap
        </IonContent>
      </IonMenu>

      <IonPage id="contenido">
        <IonToolbar>
          <IonItem>
            <IonAvatar slot="start">
              <img alt="Silhouette of a person's head" src="https://ionicframework.com/docs/img/demos/avatar.svg" />
            </IonAvatar>
            <p>Hola, "insertar usuario de gravicap"</p> 
          </IonItem>
          <IonButtons slot="end">
            <IonMenuButton></IonMenuButton>
          </IonButtons>
        </IonToolbar>

        <IonContent className="ion-padding">
          <IonNavLink routerDirection="forward" component={() => <GeneratedEnergy />}>
            <IonCard>
              <p>Carta de link hacia la pantalla energía generada</p>
            </IonCard>
          </IonNavLink>

          <IonNavLink routerDirection="forward" component={() => <BatteryCharge />}> 
            <IonCard>
              <p>Carta de link hacia la pantalla de carga de la batería</p>
            </IonCard>
          </IonNavLink>
        
        <IonCard>
          <IonNavLink routerDirection="forward" component={() => <MyConsumption />}> 
            <IonCard>
              <p>Link mi consumo</p>
            </IonCard>
          </IonNavLink>
          <IonNavLink routerDirection="forward" component={() => <SolarPanel />}> 
            <IonCard>
              <p>Link panel solar</p>
            </IonCard>
          </IonNavLink>
          <IonNavLink routerDirection="forward" component={() => <BatteryValues />}> 
            <IonCard>
              <p>Link valores de la batería</p>
            </IonCard>
          </IonNavLink>
        </IonCard>
        </IonContent>
      </IonPage>
		</IonApp>
	);
}

export default Start;