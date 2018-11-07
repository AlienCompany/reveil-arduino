#include <Arduino.h>
#include "Util.h"
#include "CommunicationService.h"
#include "Led.h"
#include "Sensor.h"
//#include <LiquidCrystal_I2C.h>

const uint8_t PIN_SENSOR = 2;
const uint8_t PIN_LED1 = 3;
const uint8_t PIN_LED2 = 3;

//char* SERVER = "letterbox.notraly.fr";
//IPAddress SERVER(192,168,1,20);
CommunicationService *communicationService ;

Led *led1;
Led *led2;
Sensor *sensor1;


void setup() {
    Serial.begin(9600);

    led1 = new Led(PIN_LED1, 0);
    led2 = new Led(PIN_LED2, 0);
    sensor1 = new Sensor(PIN_SENSOR, 200);

    pinMode(PIN_SENSOR, INPUT);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);

    led1->init();
    led2->init();

//    communicationService = CommunicationService::getInstance();
//    communicationService->init();
//    communicationService->setServer(SERVER);
    delay(1);
}

void loop() {

    sensor1->checkChange();

    if(sensor1->getState() == OPENED){
        led1->setBrightness(255);
        led2->setBrightness(0);
    } else {
        led1->setBrightness(0);
        led2->setBrightness(255);
    }

//    communicationService->loop();

}
