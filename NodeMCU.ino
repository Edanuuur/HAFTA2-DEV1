
#include <Blynk.h>
#define yesil D2
#define kirmizi D3
#define sari D4

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int butondurumu=0;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "X_tb2hZ0IFBHxOqPqT39mWyKXw6Pbolv";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VodafoneNet-J7AL5S";
char pass[] = "Fsee.ee012";


BLYNK_WRITE(V1){
 int pinValue = param.asInt();

 if (pinValue==1){
  digitalWrite(D2,HIGH);
  delay(5000);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  delay(5000);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
  delay(5000);
  digitalWrite(D4,LOW);
  butondurumu=1;
}

else {
digitalWrite(D2,LOW);
digitalWrite(D3,LOW);
digitalWrite(D4,LOW);
butondurumu=0;
}
}

void setup()
{
// Debug console
Serial.begin(9600);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);

 Blynk.begin(auth, ssid, pass);
// You can also specify server:
//Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
//Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
Blynk.run();
}
