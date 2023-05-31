/*
 * Projet de fin d'étude: Station d'irrigation
 * Par: Mikael Leclerc
 * 
 * Description du programme: 
 * Au démarrage du programme, une connexion Wifi et une connexion Thingsboard son effectuer. Par la suite, durant tout la durée de son fonctionnement, le programme
 * assure l'aquisition de données environnemental tel que l'humdité, la température et la luminosité. Il assure également l'aquisition de donnée de température du sol.
 * En parrallèle, le programme active la pompe à eau celon les aquisition d'humdité du sol et celon la variable sélectionner par l'utilisateur. 
 */




//Declaration des librairies
#include <WiFi.h>
#include <ThingsBoard.h>
#include "Max44009.h"
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

// varialbe des librairie
WiFiClient espClient;
Max44009 myLux(0x4A);
ThingsBoard tb(espClient);
// defini le menu de demarrage
int menu = 3;
//initialisation variable pour les pins des modules
const byte pinCapteurIrrigation1 = 14;
const byte pinCapteurIrrigation2 = 12;
const byte pinCapteurIrrigation3 = 13;
//initialisation Bouton
const byte pinBoutonHaut = 27;
const byte pinBoutonBas = 26;
const byte pinBoutonMenu = 25;
const byte pinBoutonStop = 33;
//initialisation pin Moteur
const byte pinMoteur = 15;
//initialisation varialbe module humiditeAir
const byte thermoDO = 19;
const byte thermoCS = 5;
const byte thermoCLK = 18;
//initialisation Ecran
const byte lcdColumns = 20;
const byte lcdRows = 4;

//initialisation variable mesure de tension capteur humidite sol
float mesureTensionCapteur1 = 0;
float mesureTensionCapteur2 = 0;
float mesureTensionCapteur3 = 0;
//initialisation variable volume d'eau
float volumeEau1 = 0;
float volumeEau2 = 0;
float volumeEau3 = 0;
//initialiosation Compteur seconde
unsigned long tempCapteur = 0;
unsigned long tempBouton = 0;
unsigned long tempsWifi = 0;
unsigned long tempsTb = 0;
unsigned long delayWifi = 0;
unsigned long tempsAttenteDemarragePompe = 0;
unsigned long tempsDemarragePompe = 0;
//EtatDeConnection
byte EtatDeConnectionTb = 1; // definie letat de la connection de thingsboard avec le microcontroleur, 0 = non connecte.. 1 = en connection.. 2 = connecte
byte EtatDeConnectionInt = 1; // definie letat de la connection du wifi avec le microcontroleur, 0 = non connecte.. 1 = en connection.. 2 = connecte


LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
//initialisation DHT22
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
#define Addr 0x4A

void setup() {
  Serial.begin(115200);
  Wire.begin();
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  pinMode(pinCapteurIrrigation1, INPUT);
  pinMode(pinCapteurIrrigation2, INPUT);
  pinMode(pinCapteurIrrigation3, INPUT);

  pinMode(pinBoutonHaut, INPUT);
  pinMode(pinBoutonBas, INPUT);
  pinMode(pinBoutonMenu, INPUT);
  pinMode(pinBoutonStop, INPUT);

  pinMode(pinMoteur, OUTPUT);

  connectionWifi(); //Onglet Wifi
  connectionTb(); //Onglet CommCloud
  mesure();

}

void loop() {
  unsigned long maintenant = millis();
  // Chronometre de 10 minutes
  if (maintenant - tempCapteur >= 600000) {
    tempCapteur = maintenant;
    
    mesure();   //Onglet Capteur
    affichageMenu3(EtatDeConnectionTb, EtatDeConnectionInt);  //Onglet Ecran
  }
  0
  commande(); //Onglet Bouton
}
