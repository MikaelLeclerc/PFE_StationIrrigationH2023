// Defini les variable des bouton
bool valBoutonHaut = LOW;
bool valBoutonBas = LOW;
bool valBoutonMenu = LOW;
bool valBoutonStop = LOW;
bool activationIrrigation = true;

void commande() {
  valBoutonHaut = digitalRead(pinBoutonHaut);
  valBoutonBas = digitalRead(pinBoutonBas);
  valBoutonMenu = digitalRead(pinBoutonMenu);
  valBoutonStop = digitalRead(pinBoutonStop);

    // si la bouton "Haut" est appuyer, executer la fonction suivante:
  if (valBoutonHaut == HIGH ) {

    selectionHumidite(valBoutonHaut, valBoutonBas); //Onglet SystemPompe

  }
    // si la bouton "BAS" est appuyer, executer la fonction suivante:
  if (valBoutonBas == HIGH  ) {

    selectionHumidite(valBoutonHaut, valBoutonBas); //Onglet SystemPompe

  }
    // si le bouton menu est appuyer, bloque le programme dans une boucle while tant que celui-ci reste appuyer. 
    // Cela empeche de devoir mettre un delai sur les boutons
  if (valBoutonMenu == HIGH) {
    while (valBoutonMenu == HIGH) {
      valBoutonMenu = digitalRead(pinBoutonMenu);
      if (valBoutonMenu != HIGH) {
        Menu(); // Onlet Ecran
        break;
      }
    }
  }

  // logique pour interupteur:
  // Permet de changer la valeurs du bouton comme un interupteur.
  if (valBoutonStop == HIGH && activationIrrigation == true) {
    while (valBoutonStop == HIGH) {
      valBoutonStop = digitalRead(pinBoutonStop);
      if (valBoutonStop != HIGH) {
        break;
      }
    }
    activationIrrigation = false;
    Serial.println("OFF");
  }

  if (valBoutonStop == HIGH && activationIrrigation == false) {
    while (valBoutonStop == HIGH) {
      valBoutonStop = digitalRead(pinBoutonStop);
      if (valBoutonStop != HIGH) {
        break;
      }
    }
    activationIrrigation = true;
    Serial.println("ON");
  }
  activationPompe(activationIrrigation); //Onglet SystemPompe
}
