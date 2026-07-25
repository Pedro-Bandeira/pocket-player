#include "SPIBus.h"

#define LCD_CS    10
#define LCD_DC    46

bool SPIBus::begin()
{
    pinMode(LCD_CS, OUTPUT);
    pinMode(LCD_DC, OUTPUT);

    digitalWrite(LCD_CS, HIGH);

    spi.begin(12, 13, 11, 10);

    return true;
}

void SPIBus::writeCommand(uint8_t cmd)
{
    spi.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    digitalWrite(LCD_DC, LOW);
    digitalWrite(LCD_CS, LOW);

    spi.transfer(cmd);

    digitalWrite(LCD_CS, HIGH);

    spi.endTransaction();
}

void SPIBus::writeData(uint8_t data)
{
    spi.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    digitalWrite(LCD_DC, HIGH);
    digitalWrite(LCD_CS, LOW);

    spi.transfer(data);

    digitalWrite(LCD_CS, HIGH);

    spi.endTransaction();
}