//*************** Documentation Section **************
// This program recieves Message from MQTT Broker 
// and processes data recieved by Adafruit.io

// Author : Harshit Srivastava
// Data : 10th Jan 2018

/************************* library included *********************************/
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "XXXXXXX" // put your Router SSID  
#define WLAN_PASS       "XXXXXXX" // put your Router password

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "xxxxx" // put your Adafruit i/o Username 
#define AIO_KEY         "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" // put the Adafruit io Key for Account authentication

/************ Client setup section( don't need to change this )******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feeds called 'light' & 'fan' for subscribing to changes.

Adafruit_MQTT_Subscribe light = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/light");

Adafruit_MQTT_Subscribe fan = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/fan");

/*************************** Sketch Code ************************************/

void MQTT_connect();

void setup() {
  Serial.begin(115200); // Setup baud rate for Serial Communication
  delay(10); 
  pinMode(16,OUTPUT); // initializes port registers of D0 or GPIO 16
  pinMode(5,OUTPUT); // initializes port registers of D1 or GPIO 5
  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); 
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("."); // prints '.' on serial Monitor on untill Device is not connected to router 
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); // prints IP address of device 

  // Setup MQTT subscription for 'light' and 'fan' feed.
  
  mqtt.subscribe(&light);
  mqtt.subscribe(&fan);
  
}

uint32_t x=0;

void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first)
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  
  while ((subscription = mqtt.readSubscription(5000))) 
  {  
    if (subscription == &light)
    {
      Serial.print(F("Got_light: "));
      Serial.println((char*)light.lastread);
      
      
      
      if ( ((char *)light.lastread)[1] == 'F' )
      {
          digitalWrite(16,LOW); // switches off Light
          delay(500);
      }
      
      else if ( ((char *)light.lastread)[1] == 'N' )
      {
          digitalWrite(16,HIGH);// switches on Light
          delay(500);
      }    
      
    }

    if (subscription == &fan) {
      Serial.print(F("Got_fan: "));
      Serial.println((char*)fan.lastread);
      
      
      if ( ((char *)fan.lastread)[1] == 'F' )
      {
          digitalWrite(5,LOW);
          delay(500);
      }
      
      else if ( ((char *)fan.lastread)[1] == 'N' )
      {
          digitalWrite(5,HIGH);
          delay(500);
      }    
    }
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
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
}
