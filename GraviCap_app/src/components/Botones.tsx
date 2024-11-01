import { IonButton, IonNavLink } from "@ionic/react";
import Graphics from "../pages/GraphicsPage";

<IonNavLink routerDirection="forward" component={() => <Graphics />}>
  <IonButton size="small">
    Página de Gráficos
  </IonButton>
</IonNavLink>