import { IonIcon, IonLabel, IonNavLink, IonRouterOutlet, IonTabBar, IonTabButton, IonTabs } from "@ionic/react";
import { IonReactRouter } from "@ionic/react-router";
import { Redirect, Route } from "react-router";
import Start from "../pages/StartPage";
import Graphics from "../pages/GraphicsPage";
import { homeOutline, trendingUpSharp } from "ionicons/icons";

function Tabs () {
  return(
    <IonReactRouter>
      <IonTabs>
        <IonRouterOutlet>
          <Redirect exact path="/" to="../StartPage" />
          {/*Use the render method to reduce the number of renders your component will have due to a route change.
          Use the component prop when your component depends on the RouterComponentProps passed in automatically.*/}
          <Route path="../StartPage" render={() => <Start />} exact={true} />
          <Route path="../GraphicsPage" render={() => <Graphics />} exact={true} />
        </IonRouterOutlet>
        <IonTabBar slot="bottom">
          <IonTabButton tab="Graphics" href="../GraphicsPage">
            <IonIcon icon={trendingUpSharp} />
            <IonLabel>Graficos de Potencia</IonLabel>
          </IonTabButton>
          <IonTabButton tab="Start" href="../StartPage">
            <IonIcon icon={homeOutline} />
            <IonLabel>Inicio</IonLabel>
          </IonTabButton>
        </IonTabBar>
      </IonTabs>
    </IonReactRouter>
  );
}

export default Tabs;