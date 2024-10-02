{/*importo las herrramientas de ionic, react y el css*/}
import {IonPage, IonInput, IonInputPasswordToggle, IonButton, IonApp, IonNavLink} from '@ionic/react';
import React from 'react';
import './CSS WelcomePage.css'; 
import Start from './StartPage';

{/*declaro la variable (la pantalla de bienvenida)*/}
function Welcome () {
  return (
    <IonApp>
      <IonPage>
        
        {/*importo la imagen del logo*/}
        <img src= "/GRAVICAPlogo.png" alt= "Logo GraviCap" className='logo'/>
        
        {/*texto de bienvenida y slogan*/}
        <p className='texto bienvenida'>Bienvenido a GraviCap</p>
        <p className='texto bienvenida'>Una forma de elevar tu energía</p>
        
        {/*poner texto y boludeces para rellenar*/}

        {/*boton para ir hacia la pagina de inicio*/}
        <IonNavLink routerDirection="forward" component={() => <Start />}> 
          <IonButton size="default" shape="round">  
            Haga Click para Continuar
          </IonButton>
        </IonNavLink>
      </IonPage>
    </IonApp>
  );
};

{/*exporto la variable*/}
export default Welcome;

