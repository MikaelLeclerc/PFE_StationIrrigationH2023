byte mesureCapteur = 0;

void mesure() {
  // Varialbe de calibration capteur humidite sol
  // Les capteur 2 et 3 sont retirer par manque de temps
  float penteCalibration1 = 1.0812;
  float penteCalibration2 = 0;
  float penteCalibration3 = 0;
  float b1 = -0.3339;
  float b2 = 0;
  float b3 = 0;

  //Lire la valeur analogique sur les pins des capteurs
  mesureTensionCapteur1 = analogRead(pinCapteurIrrigation1);
  mesureTensionCapteur2 = analogRead(pinCapteurIrrigation2);
  mesureTensionCapteur3 = analogRead(pinCapteurIrrigation3);
  //convertie la valeurs analogique en volt
  mesureTensionCapteur1 = (mesureTensionCapteur1 * 3.3) / 4095;
  mesureTensionCapteur2 = (mesureTensionCapteur2 * 3.3) / 4095;
  mesureTensionCapteur3 = (mesureTensionCapteur3 * 3.3) / 4095;

  //Convertie la tension en cm3/cm3 avec la calibration
  volumeEau1 = (((1.0 / mesureTensionCapteur1) * penteCalibration1) + b1) * 100;
  volumeEau2 = ((1.0 / mesureTensionCapteur2) * penteCalibration2) + b2;
  volumeEau3 = ((1.0 / mesureTensionCapteur3) * penteCalibration3) + b3;

  affichageMenu1(volumeEau1, volumeEau2, volumeEau3); // Onglet Ecran
  // enregistre les valeurs de temperature, humidite et luminosite dans les variable.
  float t = (dht.readTemperature() * 1.036245724) + 0.8751;
  float h = dht.readHumidity();
  float lux = myLux.getLux();
  mesureCapteur++;

  affichageMenu2(lux, h, t); // Onglet Ecran

  // Chronometre de 10 minutes
  if (mesureCapteur == 600) {
    mesureCapteur = 0;
    //envoiDeDonnee(volumeEau1, volumeEau2, volumeEau3, lux, h, t);
  }
}
