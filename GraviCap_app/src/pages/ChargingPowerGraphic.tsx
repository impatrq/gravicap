import { IonApp, IonButton, IonCard, IonIcon, IonLabel, IonDatetime} from '@ionic/react';
import { } from 'ionicons/icons';
import React from 'react';

function Charging () {
  return (
		<IonApp>
			<IonCard><p>Grafico de carga de la batería</p></IonCard>
			<IonDatetime></IonDatetime>;
		</IonApp>
	)
}

export default Charging;