int humiditeSolSelect = 0;
unsigned long temps30m = 0;
unsigned long temps3s = 0;
byte Minute = 59;
byte seconde = 60;
byte MinutePompe = 0;
byte secondePompe = 3;
unsigned long tempsPrint = 0;


void selectionHumidite(bool valBoutonHaut, bool valBoutonBas) {

  if (valBoutonHaut == HIGH && humiditeSolSelect < 100) { // pas un % d'humidite plus haut que 100%
    humiditeSolSelect++;

  }
  else if (valBoutonBas == HIGH && humiditeSolSelect > 0) { //  pas un % d'humidite plus bas que 0%
    humiditeSolSelect--;

  }

}

void activationPompe(bool activationIrrigation) {

  if (activationIrrigation == true && volumeEau1 < humiditeSolSelect) {
    // attente 1h: Permet de donner un % d'erreur, puisque le % d'eau ne diminue pas beaucoup, et que a l'inverse celui ci est facilement augmentable, cela permet de stabiliser la mesure d'humditie, bien que cela prenne du temps a faire
    unsigned long maintenant = millis();
    if (maintenant - tempsAttenteDemarragePompe <= 3600000) {

      if (maintenant - temps30m >= 1000) {
        temps30m = maintenant;
        seconde--;
        if (seconde <= 0) {
          seconde = 59;
          Minute--;
        }
        Serial.println(String(Minute) + ":" + String(seconde) + "  ATTENTE");
      }
    }

    else if (maintenant - tempsAttenteDemarragePompe >= 3600000) {


      if (maintenant - tempsDemarragePompe <= 3600000 + 3000) {
        digitalWrite(pinMoteur, HIGH);
        Serial.println("MOTEUR ON");
        if (maintenant - temps3s >= 1000) {
          temps3s = maintenant;
          secondePompe--;
        }
      }

      else if (maintenant - tempsDemarragePompe >= 3600000 + 3000) {
        digitalWrite(pinMoteur, LOW);
        Serial.println("Moteur OFF");
        tempsDemarragePompe = maintenant;
        tempsAttenteDemarragePompe = maintenant;
        Minute = 59;
        seconde = 60;
        MinutePompe = 0;
        secondePompe = 3;
      }
    }
  }
  affichageMenu4(activationIrrigation, seconde, Minute, secondePompe, MinutePompe, humiditeSolSelect);
}

/*
       le prob c'est que le taux ne sera jamais au bon niveau, sauf si je trouve une corelation entre la taille du tuyau et le taux que cela ajoute
      je pourais faire plusieurs alimentation simultanement, genre activation du moteur 3 sec, attente 5min, lecture du sol, refaire 3sec si c'est pas encore assez

*/
