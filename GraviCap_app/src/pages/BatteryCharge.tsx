import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React from 'react';
import "./CSS BatteryCharge.css"

function BatteryCharge () {
  return (
    <>
      {/*header principal de la pantalla*/}
      <IonHeader>
        {/*barra de herramientas superior*/}
        <IonToolbar>
          {/*botón ubicado en la parte de inico, en la iaquierda de la barra*/}
          <IonButtons slot="start">
            {/*botón para volver hacia la pantalla anterior*/}
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      {/*contenido central de la pantalla*/}
      <IonContent className="ion-padding">
        <div id= "paginabateria">
          <div id= "total">
            <div id= "atras">
              {/*carta circular trasera*/}
              <IonCard>
                <div id= "adelante">
                  {/*carta circular delantera contendora del valor porcentaul de la carga de batería*/}
                  <IonCard>
                    {/*valor porcentual de la carga de la batería*/}
                    <strong><p>73%</p></strong>
                  </IonCard>
                </div>
              </IonCard>
            </div>
          </div>
          <div id= "textocarga">
            <div id= "valorcarga">
              {/*valor del tiempo de carga total de la batería*/}
              <p>10 minutos</p>
            </div>
            <div id= "textoabajo">
              {/*texto del tiempo de carga*/}
              <p>para completar la carga</p>
            </div>
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default BatteryCharge;