import { IonBackButton, IonButtons, IonCard, IonContent, IonHeader, IonToolbar } from '@ionic/react';
import React from 'react';
import "./CSS GeneratedEnergy.css"
import CircularChart from './CircularGraphic';

function GeneratedEnergy () {
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
        <div id= "paginaenergiagenerada">
          {/*decalro el componente de carta circular con el valor de variación de la energía*/}
          <CircularChart value={3.5}></CircularChart>
          <br></br>
          <div id= "contenedorenergia">
            {/*carta circular para referenciar el valor con el color en el grafico*/}
            <IonCard></IonCard>
            {/*texto de energía generada*/}
            <strong>Energía Generada</strong>
            <div id= "valorpotenciaeg">
              {/*valor de potencia de energía generada en referencai con el valor del grafico*/}
              <strong>5W</strong>
            </div> 
          </div>
        </div>
      </IonContent>
    </>
	)
}

export default GeneratedEnergy;