#include <Ticker.h>
#include <IOXhop_FirebaseESP32.h>
#include <WiFi.h>

#define FIREBASE_HOST "yourFirebase.com"
#define FIREBASE_AUTH "YoUrFiRebAseaUTH"
#define WIFI_SSID "WIFI_Name"
#define WIFI_PASSWORD "wifiPassword"

String fireStatus = "";
String fireStatus1 = "";
int valvePin = 13;
int valvePin1 = 2;
bool valveOpen = false;

int valvePin2 = 18;
int valvePin3 = 19;
bool valveOpen1 = false;

bool isFirebaseConnected = false;
Ticker firebaseUpdateTicker;

void updateFirebaseStatus() {
  String status = (valveOpen) ? "1" : "0";
  Firebase.setString("valve_status", status);

  String status1 = (valveOpen1) ? "1" : "0";
  Firebase.setString("valve_status1", status1);

  Firebase.setBool("connectionStatus", isFirebaseConnected);  // send network status
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(valvePin, OUTPUT);
  digitalWrite(valvePin, LOW); // Initially, set the first valve to a closed state

  pinMode(valvePin1, OUTPUT);
  digitalWrite(valvePin1, LOW); // Initially, set the second valve to a closed state

  pinMode(valvePin2, OUTPUT);
  digitalWrite(valvePin2, LOW); // Initially, set the third valve to a closed state

  pinMode(valvePin3, OUTPUT);
  digitalWrite(valvePin3, LOW); // Initially, set the fourth valve to a closed state

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  firebaseUpdateTicker.attach(1.0, updateFirebaseStatus);
  Firebase.setString("valve_status", "0");
  Firebase.setString("valve_status1", "0");

  isFirebaseConnected = true;  
}

void loop() {
  fireStatus = Firebase.getString("valve_status");
  fireStatus1 = Firebase.getString("valve_status1");

  if (fireStatus == "1" && !valveOpen) {
    Serial.println("Valve status ON");
    digitalWrite(valvePin, HIGH);
    valveOpen = true;
    delay(1000);
    digitalWrite(valvePin, LOW);
  } else if (fireStatus == "0" && valveOpen) {
    Serial.println("Valve Status OFF");
    digitalWrite(valvePin, LOW);
    valveOpen = false;
    digitalWrite(valvePin1, HIGH);
    delay(1000);
    digitalWrite(valvePin1, LOW);
  } else {
    Serial.println("Wrong Credential! Please send ON/OFF for valve 1");
  }

  if (fireStatus1 == "1" && !valveOpen1) {
    Serial.println("Valve status ON");
    digitalWrite(valvePin2, HIGH);
    valveOpen1 = true;
    delay(1000);
    digitalWrite(valvePin2, LOW);
  } else if (fireStatus1 == "0" && valveOpen1) {
    Serial.println("Valve Status OFF");
    digitalWrite(valvePin2, LOW);
    valveOpen1 = false;
    digitalWrite(valvePin3, HIGH);
    delay(1000);
    digitalWrite(valvePin3, LOW);
  } else {
    Serial.println("Wrong Credential! Please send ON/OFF for valve 2");
  }
}
