//Made for the LinkNodeR4 (for Amazon Alexa and Home Assistant)
//Made by Computerfreek274 and GRAnimated
//Source : https://github.com/Computerfreek274/ln4alexa
//Won't be found with v2 Echo/Echo Plus
//Echo Dot will work
//If you do not have an echo dot, use Home Assistant and habridge.

#include <ESP8266WiFi.h>
#include "WemoSwitch.h"
#include "WemoManager.h"
#include "CallbackFunction.h"

// prototypes
boolean connectWifi();

//on/off callbacks
void lightOn();
void lightOff();
void secondOn();
void secondOff();
void thirdOn();
void thirdOff();
void fourthOn();
void fourthOff();

//int relayOne = 12;
//int relayTwo = 13;
//int relayThree = 14;
//int relayFour = 16;

//------- Replace the following! ------
char ssid[] = "xxxx";       // your network SSID (name)
char password[] = "xxxx";  // your network key

WemoManager wemoManager;
WemoSwitch *light = NULL;
WemoSwitch *second = NULL;
WemoSwitch *third = NULL;
WemoSwitch *fourth = NULL;

void setup()
{
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  wemoManager.begin(); //Begin
  // Format: Alexa invocation name, local port no, on callback, off callback
  light = new WemoSwitch("relay one", 80, lightOn, lightOff);
  second = new WemoSwitch("relay two", 81, secondOn, secondOff);
  third = new WemoSwitch("relay three", 82, thirdOn, thirdOff);
  fourth = new WemoSwitch("relay four", 83, fourthOn, fourthOff);
  wemoManager.addDevice(*light);
  wemoManager.addDevice(*second);
  wemoManager.addDevice(*third);
  wemoManager.addDevice(*fourth);
  
  pinMode(12, OUTPUT); // initialize digital relayone as an output.
  delay(10);
  digitalWrite(12, LOW); // Low = off, High = on

  pinMode(13, OUTPUT); // initialize digital relayone as an output.
  delay(10);
  digitalWrite(13, LOW); // Low = off, High = on

  pinMode(14, OUTPUT); // initialize digital relayone as an output.
  delay(10);
  digitalWrite(14, LOW); // Low = off, High = on

  pinMode(16, OUTPUT); // initialize digital relayone as an output.
  delay(10);
  digitalWrite(16, LOW); // Low = off, High = on
}

void loop()
{
  wemoManager.serverLoop();
}

void lightOn() { //First
    Serial.print("Switch 1 turn on ...");
    digitalWrite(12, HIGH);
}

void lightOff() { //First
    Serial.print("Switch 1 turn off ...");
    digitalWrite(12, LOW);
}


void secondOn() { //Second
    Serial.print("Switch 2 turn on ...");
    digitalWrite(13, HIGH);
}

void secondOff() { //Second
    Serial.print("Switch 2 turn off ...");
    digitalWrite(13, LOW);
}


void thirdOn() { //Third
    Serial.print("Switch 3 turn on ...");
    digitalWrite(14, HIGH);
}

void thirdOff() { //Third
    Serial.print("Switch 3 turn off ...");
    digitalWrite(14, LOW);
}


void fourthOn() { //Fourth
    Serial.print("Switch 4 turn on ...");
    digitalWrite(16, HIGH);
}

void fourthOff() { //Fourth
    Serial.print("Switch 4 turn off ...");
    digitalWrite(16, LOW);
}

