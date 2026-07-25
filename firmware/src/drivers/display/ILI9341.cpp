#include "ILI9341.h"

static const uint8_t cmdCF[] = {0x00, 0xC1, 0x30};
static const uint8_t cmdED[] = {0x64, 0x03, 0x12, 0x81};

static const InitCommand initSequence[] =
{
    {0xCF, cmdCF, sizeof(cmdCF), 0},
    {0xED, cmdED, sizeof(cmdED), 0},
};

#define LCD_BL 45

bool ILI9341::begin()
{
    pinMode(LCD_BL, OUTPUT);
    digitalWrite(LCD_BL, HIGH);

    spi.begin();

    delay(200);

    command(0x01);
    delay(150);

    initRegisters();

    command(0x11);
    delay(120);

    command(0x29);

    return true;
}

void ILI9341::fillScreen(uint16_t color)
{

}

void ILI9341::command(uint8_t cmd)
{
    spi.writeCommand(cmd);
}

void ILI9341::data(uint8_t value)
{
    spi.writeData(value);
}

void ILI9341::initRegisters()
{
    Serial.println("Inicializando registradores...");

    for (const auto& cmd : initSequence)
    {
        sendCommand(cmd);
    }

    Serial.println("Registradores enviados.");
}

void ILI9341::sendCommand(const InitCommand& cmd)
{
    command(cmd.command);

    for (uint8_t i = 0; i < cmd.length; i++)
    {
        data(cmd.data[i]);
    }

    if (cmd.delayMs > 0)
    {
        delay(cmd.delayMs);
    }
}