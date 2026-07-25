#include <Arduino.h>

#define LCD_BL 45

void setup()
{
    Serial.begin(115200);

    pinMode(LCD_BL, OUTPUT);

    digitalWrite(LCD_BL, HIGH);

    Serial.println("Backlight ligado!");
}

void loop()
{
}