

void affichageMenu1(float volumeEau1, float volumeEau2, float volumeEau3) { //CapteurSol
  if (menu == 1) {
    lcd.setCursor(0, 0);
    lcd.print("MENU1: HUMIDITE SOL");
    lcd.setCursor(0, 1);
    lcd.print(" 1: cm3/cm3= ");
    lcd.setCursor(14, 1);
    //lcd.print(volumeEau1);
    lcd.print(volumeEau1);
    //--
    //lcd.setCursor(0, 2);
    //lcd.print(" 2: cm3/cm3= ");
    //lcd.setCursor(14, 2);
    //lcd.print(volumeEau2);
    //--
    //lcd.setCursor(0, 3);
    //lcd.print(" 3: cm3/cm3= ");
    //lcd.setCursor(14, 3);
    //lcd.print(volumeEau3);
  }

}

void affichageMenu2(float lux, float h, float t) { //Capteur meteorologique
  if (menu == 2) {
    lcd.setCursor(0, 0);
    lcd.print("MENU2: METEO");
    lcd.setCursor(0, 1);
    lcd.print(" Temperature: ");
    lcd.setCursor(15, 1);
    lcd.print(t);
    //--
    lcd.setCursor(0, 2);
    lcd.print(" Humidite: ");
    lcd.setCursor(15, 2);
    lcd.print(h);
    //--
    lcd.setCursor(0, 3);
    lcd.print(" Luminosite: ");
    lcd.setCursor(15, 3);
    lcd.print(lux);
  }
}

void affichageMenu3(int EtatDeConnectionTb, int EtatDeConnectionInt) { //Connection Wifi et thingsboard
  if (menu == 3) {
    lcd.setCursor(0, 0);
    lcd.print("MENU3: Connexion");
    lcd.setCursor(0, 1);
    lcd.print(" ThingsBoard: ");

    //Determine l'affichage selon lettat de la connexion
    if (EtatDeConnectionTb == 0) {
      lcd.setCursor(15, 1);
      lcd.print("     "); //efface la ligne pour ajouter le message qui suit
      lcd.setCursor(15, 1);
      lcd.print("Echec");
    }
    else if (EtatDeConnectionTb == 1) {
      lcd.setCursor(15, 1);
      lcd.print("     ");
      lcd.setCursor(15, 1);
      lcd.print("...");

    }
    else if (EtatDeConnectionTb == 2) {
      lcd.setCursor(15, 1);
      lcd.print("     ");
      lcd.setCursor(15, 1);
      lcd.print("O.K");

    }
    lcd.setCursor(0, 2);
    lcd.print(" Co WiFi: ");

    if (EtatDeConnectionInt == 0) {
      lcd.setCursor(15, 2);
      lcd.print("     ");
      lcd.setCursor(15, 2);
      lcd.print("Echec");
    }
    else if (EtatDeConnectionInt == 1) {
      lcd.setCursor(15, 2);
      lcd.print("     ");
      lcd.setCursor(15, 2);
      lcd.print("...");
    }
    else if (EtatDeConnectionInt == 2) {
      lcd.setCursor(15, 2);
      lcd.print("     ");
      lcd.setCursor(15, 2);
      lcd.print("O.K");
    }

  }
}

void affichageMenu4(bool activationIrrigation, byte seconde, byte Minute, byte secondePompe, byte MinutePompe, int humiditeSolSelect) { // Pompe
  if (menu == 4) {
    lcd.setCursor(0, 0);
    lcd.print("MENU4: Pompe");
    lcd.setCursor(0, 1);
    lcd.print(" attente: ");
    lcd.setCursor(10, 1);
    lcd.print("     ");
    lcd.setCursor(10, 1);
    lcd.print(Minute);
    lcd.setCursor(12, 1);
    lcd.print(":");
    lcd.setCursor(13, 1);
    lcd.print("  ");
    lcd.setCursor(13, 1);
    lcd.print(seconde);
    if (activationIrrigation == true) {
      lcd.setCursor(12, 0);
      lcd.print("   ");
      lcd.setCursor(12, 0);
      lcd.print("ON");
    }
    else if (activationIrrigation == false) {
      lcd.setCursor(12, 0);
      lcd.print("   ");
      lcd.setCursor(12, 0);
      lcd.print("OFF");
    }
    lcd.setCursor(0, 2);
    lcd.print(" pompage: ");
    lcd.setCursor(10, 2);
    lcd.print("  ");
    lcd.setCursor(10, 2);
    lcd.print(MinutePompe);
    lcd.setCursor(11, 2);
    lcd.print(":");
    lcd.setCursor(13, 2);
    lcd.print(secondePompe);

    lcd.setCursor(0, 3);
    lcd.print(" Humidite: ");
    lcd.setCursor(11, 3);
    lcd.print("   ");
    lcd.setCursor(11, 3);
    lcd.print(humiditeSolSelect);

  }
}

void Menu() {
  menu++;
  if (menu >= 5) {
    menu = 1;
  }
  
  lcd.clear();
}
