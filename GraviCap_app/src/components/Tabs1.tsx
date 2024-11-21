import { IonIcon, IonLabel, IonTabBar, IonTabButton, IonTabs } from "@ionic/react";
import { homeOutline } from "ionicons/icons";
import React from "react";


function Tabs1 () {
  return (
    <IonTabs>
      <IonTabBar slot= "bottom">
        <IonTabButton tab= "start">
          <IonIcon icon={homeOutline} />
          <IonLabel>Inicio</IonLabel>
        </IonTabButton>
      </IonTabBar>
    </IonTabs>
  )
}

export default Tabs1;