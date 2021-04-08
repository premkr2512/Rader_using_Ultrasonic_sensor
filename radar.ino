#include "ESP8266WiFi.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define WLAN_SSID       "AndroidAP"
#define WLAN_PASS       "098765432111"
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                  
#define AIO_USERNAME    "Prem2512"
#define AIO_KEY         "038bdc81de394b85abbf082221532aef"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);


Adafruit_MQTT_Publish data = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/TXT");
Adafruit_MQTT_Publish data1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/TXT");


void MQTT_connect();
#include <Servo.h>. 
#include<LiquidCrystal.h>
LiquidCrystal lcd(D3,D4,D5,D6,D7,D8); 
#define trigPin = D0;
#define echoPin = D1;

long duration;
int distance;
Servo myServo; 

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT); 

Serial.begin(9600);
myServo.attach(D2); 
void loop()
{




}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
