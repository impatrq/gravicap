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
            {/*bienvenida y slogan*/}
            <div id= "letrasbienvenida">
              <p><strong>Bienvenido a GraviCap</strong></p>
              <p><strong>Una forma de elevar tu energía</strong></p>
              <div id= "textocentro">
                <p> {/*texto informativo sobre gravicap y breve explicaión de la aplicación y lo que verá*/}
                  Nuestro producto "GraviCap" es una batería de almacenamiento gravitatorio, la cual podrá darle energía por medio de la fuerza de la gravedad.
                  <br></br>
                  En nuestra aplicación podrá monitorear sus distnitos valores, como la energía que genera o porcentaje de carga. Así también, dispondrá de graficos y una interfaz amigable con la que podrá ver estos valores.
                  <br></br>
                  Más abajo se encuentra un botón amarillo, el cual lo llevará a la pantalla principal de inicio.
                </p>
              </div>
            </div>
            {/*ruta de navegación hacia la pagina de inicio*/}
            <IonNavLink routerDirection="forward" component={() => <Start />}> 
            {/*botón de tamaño pequeño amarillo en la parte inferiror*/}
              <IonButton size="small" shape="round">  
                Pulse Aquí para ir a Inicio
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

