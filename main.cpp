#include <Arduino.h>
#include "Util.h"
#include "CommunicationService.h"
#include "Led.h"
#include "Sensor.h"
#include "Lcd.h"



//char* SERVER = "letterbox.notraly.fr";
//IPAddress SERVER(192,168,1,20);
//CommunicationService *communicationService ;
Lcd *lcd;


void setup() {
    Serial.begin(9600);

   lcd = new Lcd(0x27,20, 4);
   lcd->init();

//    communicationService = CommunicationService::getInstance();
//    communicationService->init();
//    communicationService->setServer(SERVER);
//    delay(1);
}

void loop() {

//    communicationService->loop();

}
