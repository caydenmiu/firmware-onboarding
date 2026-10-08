#include "LEDController.h"

void LEDController::begin()
{
    pinMode(ledPin, OUTPUT);
}

float LEDController::updateTemp(float temp)
{
    controlRATE(temp);

    if (millis() - toggletime >= timebetweenblinks)
    {
        toggletime = millis();
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }

    return temp;
}

void LEDController::controlRATE(float temp)
{
    if (temp < 20.0)
        timebetweenblinks = 1000;
    else if (temp < 30.0)
        timebetweenblinks = 500;
    else
        timebetweenblinks = 100;
}