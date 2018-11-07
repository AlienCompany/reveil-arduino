#include <Arduino.h>
#include "Util.h"
#include "CommunicationService.h"
#include "Led.h"
#include "Sensor.h"
#include <LiquidCrystal_I2C.h>



//char* SERVER = "letterbox.notraly.fr";
//IPAddress SERVER(192,168,1,20);
//CommunicationService *communicationService ;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
    Serial.begin(9600);

    lcd.begin();
    lcd.backlight();
    lcd.home();
    lcd.print("Bonjour");

//    communicationService = CommunicationService::getInstance();
//    communicationService->init();
//    communicationService->setServer(SERVER);
//    delay(1);
}

void loop() {

//    communicationService->loop();

}
