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
    lcdI2C->print("00:00:00");
}

Lcd::Lcd(uint8_t address, uint8_t column, uint8_t row) {
    lcdI2C = new LiquidCrystal_I2C(address, column, row);
}

Lcd::~Lcd() = default;

void Lcd::printHour(String hour) {
    lcdI2C->print(hour);
}
