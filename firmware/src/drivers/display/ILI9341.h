#pragma once

#include <Arduino.h>
#include "../spi/SPIBus.h"

struct InitCommand
{
    uint8_t command;
    const uint8_t* data;
    uint8_t length;
    uint16_t delayMs;
};

class ILI9341
{
public:

    bool begin();

    void fillScreen(uint16_t color);

    void command(uint8_t cmd);

    void data(uint8_t value);

private:
    SPIBus spi;

    void initRegisters();
    void sendCommand(const InitCommand& cmd);
};