{/*importo las herrramientas de ionic, react y el css*/}
import {IonPage, IonButton, IonApp, IonNavLink, IonContent} from '@ionic/react';
import React from 'react';
import './CSS WelcomePage.css'; 
import Start from './StartPage';

{/*declaro la función (la pantalla de bienvenida)*/}
function Welcome () {
  return (
    <IonApp>
      <IonPage>
        {/*contendio de la pantalla*/}
        <IonContent className="ion-padding">
          <div id= "bienvenida">
            {/*imagen del logo*/}
            <img src= "/GRAVICAPlogo.png" alt= "Logo GraviCap"/>
            {/*texto de bienvenida y slogan*/}
            <div id= "letrasbienvenida">
              <p><strong>Bienvenido a GraviCap</strong></p>
              <p><strong>Una forma de elevar tu energía</strong></p>
              {/*poner texto y boludeces para rellenar*/}
            </div>
            {/*ruta de navegación hacia la pagina de inicio*/}
            <IonNavLink routerDirection="forward" component={() => <Start />}> 
            {/*botón amarillo en la parte inferiror decalrado dentro de la ruta*/}
              <IonButton size="default" shape="round">  
                Haga Click para Continuar
              </IonButton>
            </IonNavLink>
          </div>
        </IonContent>
      </IonPage>
    </IonApp>
  );
};

{/*exporto la variable*/}
export default Welcome;

