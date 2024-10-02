import { IonIcon, IonLabel, IonRouterOutlet, IonTabBar, IonTabButton, IonTabs } from "@ionic/react";
import { IonReactRouter } from "@ionic/react-router";
import { Route } from "react-router";
import Start from "../pages/StartPage";
import Graphics from "../pages/GraphicsPage";
import User from "../pages/UserPage";
import { homeOutline, personCircleOutline, trendingUpSharp } from "ionicons/icons";

function Tabs () {
  return(
    <IonReactRouter> 
      <IonTabs>
        <IonRouterOutlet>
          <Route path="/StartPage" render={() => <Start />} exact={true} />
          <Route path="/GraphicsPage" render={() => <Graphics />} exact={true} />
          <Route path="/UserPage" render={() => <User />} exact={true} />

          <IonTabBar slot="bottom">
            <IonTabButton tab="Graphics" href="/GraphicsPage">
              <IonIcon icon={trendingUpSharp} />
              <IonLabel>Graficos de Potencia</IonLabel>
            </IonTabButton>

            <IonTabButton tab="Start" href="/StartPage">
              <IonIcon icon={homeOutline} />
              <IonLabel>Inicio</IonLabel>
            </IonTabButton>

            <IonTabButton tab="User" href="/UserPage">
              <IonIcon icon={personCircleOutline} />
              <IonLabel>Usuario</IonLabel>
            </IonTabButton>
          </IonTabBar>
        </IonRouterOutlet>
      </IonTabs>
    </IonReactRouter>
  );
}

export default Tabs;