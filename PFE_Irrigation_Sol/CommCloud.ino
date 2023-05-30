// Information de connexion pour le serveur thingsboard:
#define THINGSBOARD_SERVER  "thingsboard.cloud"
#define TOKEN "znTLbWmgNf46V7h8CoB6"

bool connectionThingsboard = false;

void connectionTb() {
  // effectue la connexion au serveur thingsboard
  while (!tb.connected()) {
    EtatDeConnectionTb = 1;
    affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt); // Onglet Ecran

    if ( tb.connect(THINGSBOARD_SERVER, TOKEN) ) {
      Serial.println( "[DONE]" );
      connectionThingsboard = true;
      EtatDeConnectionTb = 2;
      affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt);
    }
    unsigned long maintenant = millis();
    if (maintenant - tempsTb >= 25000) {
      Serial.print( "fail" );
      connectionThingsboard = false;
      EtatDeConnectionTb = 0;
      affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt);
      break;
    }
  }
}


void envoiDeDonnee(float volumeEau1, float volumeEau2, float volumeEau3, float t, float h, float lux) {
  // Envoi les donnees au serveur

  if (connectionThingsboard == true) {
    Serial.println("Envoi");

    if (isnan(volumeEau1)) {
      Serial.println("erreur Humdidite #1");
    }
    else {
      tb.sendTelemetryFloat("Humidite #1", volumeEau1);
    }


    if (isnan(volumeEau2)) {
      Serial.println("erreur humidite #2");
    }
    else {
      tb.sendTelemetryFloat("Humidite #2", volumeEau2);
    }


    if (isnan(volumeEau3)) {
      Serial.println("erreur humidite #3");
    }
    else {
      tb.sendTelemetryFloat("Humidite #2", volumeEau3);
    }

    if (isnan(t)) {
      Serial.println("erreur Temperature");
    }
    else {
      tb.sendTelemetryFloat("Temperature", t);
    }


    if (isnan(h)) {
      Serial.println("erreur humidite Air");
    }
    else {
      tb.sendTelemetryFloat("Humidite Air", h);
    }


    if (isnan(lux)) {
      Serial.println("erreur Luminosite");
    }
    else {
      tb.sendTelemetryFloat("Luminosite", lux);
    }

  }
}
