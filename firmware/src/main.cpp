#include <Arduino.h>
#include "drivers/display/ILI9341.h"

ILI9341 display;

void setup()
{
    Serial.begin(115200);

    delay(2000);

    Serial.println();
    Serial.println("======================");
    Serial.println("PocketPlayer");
    Serial.println("======================");

    display.begin();

    Serial.println("Cheguei ao fim do setup");
}

void loop()
{
    Serial.println("Loop...");
    delay(1000);
}