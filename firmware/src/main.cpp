#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    // Aguarda a serial inicializar
    delay(3000);

    Serial.println();
    Serial.println("==============================");
    Serial.println("PocketPlayer v0.1.0");
    Serial.println("==============================");
    Serial.println("Setup executado!");
}

void loop()
{
    Serial.println("Loop executando...");
    delay(1000);
}