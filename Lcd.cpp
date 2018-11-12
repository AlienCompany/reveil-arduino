//
// Created by ferna on 08/11/2018.
//
#include <LiquidCrystal_I2C.h>
#include "Lcd.h"


void Lcd::init() {

    lcdI2C->begin();
    lcdI2C->backlight();
    lcdI2C->home();
    lcdI2C->clear();

}

Lcd::Lcd(uint8_t address, uint8_t column, uint8_t row) {
    lcdI2C = new LiquidCrystal_I2C(address, column, row);
}

Lcd::~Lcd() = default;


void Lcd::printHour() {

    lcdI2C->setCursor(0, 0);

    if (hours < 10) {
        lcdI2C->print('0');
    }
    lcdI2C->print(hours);
    lcdI2C->print(":");
    if (minutes < 10) {
        lcdI2C->print('0');
    }
    lcdI2C->print(minutes);
    lcdI2C->print(":");
    if (seconds < 10) {
        lcdI2C->print('0');
    }
    lcdI2C->print(seconds);


}

void Lcd::hour() {

    if (seconds < 59) {
        seconds += 1;
    } else {
        seconds = 00;
        if (minutes < 59) {
            minutes += 1;
        } else {
            minutes = 00;
            if (hours < 23) {
                hours += 1;
            } else {
                hours = 00;
            }
        }
    }

}
