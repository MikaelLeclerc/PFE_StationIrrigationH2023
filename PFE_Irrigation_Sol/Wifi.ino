const char* ssid = "CAL-Techno";  // Enter SSID ici
const char* password = "technophys123";  //Enter MP ici

void timerConnection() {
  //chronomètre de 1seconde, nous indique que la connection tente d'être établie.
  unsigned long maintenant = millis();
  if (maintenant - tempsWifi >= 1000) {
    tempsWifi = maintenant;
    Serial.print("."); // signale que la connection Wifi est en cours.
    EtatDeConnectionInt = 1;
    affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt);
  }
}

void connectionWifi() {
  //effectue la connection Wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);  // effectue la connection avec les varaible SSID et password du modem internet
  while (WiFi.status() != WL_CONNECTED) {
    timerConnection();
    unsigned long maintenant = millis();
    if (maintenant - delayWifi >= 20000) {
      EtatDeConnectionInt = 0;
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connecter..!"); // Signale que la connection Wifi a été établie.
    EtatDeConnectionInt = 2;
    affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt);
    IPAddress ip;
    ip = WiFi.localIP();
    Serial.print("IP: ");
    Serial.print(ip);
  }
}
