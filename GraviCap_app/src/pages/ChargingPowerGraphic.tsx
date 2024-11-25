import { IonCard, IonHeader, IonToolbar, IonButtons, IonBackButton, IonContent} from '@ionic/react';
import { } from 'ionicons/icons';
import "./CSS ChargingPowerGraphics.css"
import React from 'react';
import LineChart from './LineChartCharging';

function Charging () {
	return (
    <> {/*toda la barra de header con el botoó para ir hacia atrás*/}
      <IonHeader>
        <IonToolbar>
          <IonButtons slot="start">
            <IonBackButton></IonBackButton>
          </IonButtons>
        </IonToolbar>
      </IonHeader>
      {/*contenido de la pantalla*/}
      <IonContent className="ion-padding">
        <div id= "contenidocarga">
          {/*carta con el gráfico*/}
          <IonCard>
            {/*declaro el gráfico de linea que está en otro archivo*/}
            <LineChart></LineChart>
          </IonCard>
        </div>
      </IonContent>
    </>
	)
}

export default Charging;