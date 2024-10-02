import { Redirect, Route } from 'react-router-dom';
import { IonApp, IonIcon, IonLabel, IonNav, IonRouterOutlet, IonTabBar, IonTabButton, IonTabs, setupIonicReact } from '@ionic/react';
import { homeOutline, personCircleOutline, trendingUpSharp } from 'ionicons/icons'
import { IonReactRouter } from '@ionic/react-router';
import Start from './pages/StartPage'
import Home from './pages/WelcomePage';
import Welcome from './pages/WelcomePage';
import Graphics from "./pages/GraphicsPage"
import User from "./pages/UserPage"
/* Core CSS required for Ionic components to work properly */
import '@ionic/react/css/core.css';

/* Basic CSS for apps built with Ionic */
import '@ionic/react/css/normalize.css';
import '@ionic/react/css/structure.css';
import '@ionic/react/css/typography.css';

/* Optional CSS utils that can be commented out */
import '@ionic/react/css/padding.css';
import '@ionic/react/css/float-elements.css';
import '@ionic/react/css/text-alignment.css';
import '@ionic/react/css/text-transformation.css';
import '@ionic/react/css/flex-utils.css';
import '@ionic/react/css/display.css';

/* import '@ionic/react/css/palettes/dark.always.css'; */
/* import '@ionic/react/css/palettes/dark.class.css'; */
import '@ionic/react/css/palettes/dark.system.css';

/* Theme variables */
import './theme/variables.css';

setupIonicReact();

function App() {
  return (
    <IonReactRouter>
      <IonNav root={() => <Welcome />}></IonNav>
    </IonReactRouter>
  );
}

export default App;

