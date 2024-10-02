import { IonApp, IonBackButton, IonButton, IonButtons, IonCard, IonContent, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import React from 'react';

function BatteryValues () {
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
				<IonCard>
					{/*colocar grafico del porcentaje de carga de la batería*/}
				</IonCard>
				<IonCard><p>valores batería</p></IonCard> {/*grafico de columnas de valores de la bateria hacerlo con valores de la base de datos*/}
				<IonCard> {/*carta de valores del grafico poner valores de la base de datos */}
					<p>Voltaje</p> <p>Amperaje</p> <p>Wataje</p>
					<IonCard><p>x V</p></IonCard>
					<IonCard><p>x A</p></IonCard>
					<IonCard><p>x W</p></IonCard>
				</IonCard>
			</IonContent>
		</>
	)
}

export default BatteryValues;