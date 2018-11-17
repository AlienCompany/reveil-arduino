#define _ESPLOGLEVEL_ 4

#include <Arduino.h>
#include <WiFiEsp.h>
#include "Util.h"
#include "CommunicationService.h"
#include "Led.h"
#include "Sensor.h"
#include "Lcd.h"
#include "Reveille.h"


//char* SERVER = "letterbox.notraly.fr";
//IPAddress SERVER(192,168,1,20);
//CommunicationService *communicationService ;
Lcd *lcd;
long time;
long oldTime = 0;

char ssid[] = "Livebox-32CC";               // your network SSID (name)
char pass[] = "547AEF16514955276FA6642371"; // your network password
int status = WL_IDLE_STATUS;                // the Wifi radio's status



void setup() {

    lcd = new Lcd(0x27, 20, 4);
    lcd->init();
    lcd->loading("Init: Serials",0.f);

    Serial2.begin(115200);
    Serial.begin(115200);
    lcd->loading("Init: Wifi",0.1f);
    WiFi.init(&Serial2);
    Serial.println("Init finished");
    delay(1000);
    while (WiFi.status() == WL_NO_SHIELD) {
        lcd->loading("Init: Wifi retry",0.15f);
        Serial.print("Status: ");
        Serial.println(WiFi.status());
        Serial.println("WiFi shield not present");
        // don't continue

        delay(3000);
        WiFi.init(&Serial2);
    }

    lcd->loading("Connecting to",ssid,0.4f);
    // attempt to connect to WiFi network
    while ( status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network
        status = WiFi.begin(ssid, pass);
        lcd->loading("Retry Connecting to",ssid,0.45f);
    }

    lcd->loading("Load localIP",ssid,.85f);
    Serial.println("You're connected to the network");
    IPAddress ip = WiFi.localIP();
    while (ip == INADDR_NONE){
        delay(200);
        lcd->loading("Retry load localIP",ssid,.9f);
        ip = WiFi.localIP();
    }
    lcd->clear();
    lcd->printIp(ip);
    lcd->printWiFiFirmwareVersion(WiFi.firmwareVersion());

//    communicationService = CommunicationService::getInstance();
//    communicationService->init();
//    communicationService->setServer(SERVER);
//    delay(1);
}

void loop() {

    time = millis();
    if (time >= oldTime + 1000) {
        lcd->hour();
        lcd->printHour();
        oldTime += 1000;
    }

//    communicationService->loop();

}
