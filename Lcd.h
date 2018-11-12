//
// Created by ferna on 08/11/2018.
//

#ifndef REVEIL_LCD_H
#define REVEIL_LCD_H

#include "LiquidCrystal_I2C.h"

class Lcd {
private:
    LiquidCrystal_I2C *lcdI2C;

    int seconds = 00;
    int minutes = 00;
    int hours = 00;


public:
    Lcd(uint8_t address, uint8_t column, uint8_t row);

    void init();

    void hour();

    void printHour();

    ~Lcd();
};


#endif //REVEIL_LCD_H
