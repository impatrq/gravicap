import {IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React from 'react';
import "./CSS BatteryValues.css"
import BarChart from './GraphicValues';

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
        <div id= "paginavaloresbateria">
          <IonCard>
            <BarChart></BarChart>
          </IonCard>
          <div id="carta">
            <IonCard>
              <div id= "contenedor3valores">
                <div id= "voltajecolumna">
                  <IonCard>
                    <strong>24V</strong>
                  </IonCard>
                </div>
                <div id= "corrientecolumna">
                  <IonCard>
                    <strong>5A</strong>
                  </IonCard>
                </div>
                <div id= "potenciacolumna">
                  <IonCard>
                    <strong>15W</strong>
                  </IonCard>
                </div>
              </div>
            </IonCard>
          </div>
        </div>
			</IonContent>
		</>
	)
}

export default BatteryValues;