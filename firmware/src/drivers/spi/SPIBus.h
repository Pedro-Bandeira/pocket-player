#pragma once

#include <Arduino.h>
#include <SPI.h>

class SPIBus
{
public:
    bool begin();

    void writeCommand(uint8_t cmd);

    void writeData(uint8_t data);

private:
    SPIClass spi = SPIClass(FSPI);
};