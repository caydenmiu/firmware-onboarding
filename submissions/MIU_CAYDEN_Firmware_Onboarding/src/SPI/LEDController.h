#pragma once
#include <Arduino.h>
#include "BMEConstants.h"
#include <etl/singleton.h>

class LEDController
{
public:
    LEDController(uint8_t pin = BMEConstants::LED_PIN) : ledPin(pin) {}

    void begin();
    float updateTemp(float temp);
    void controlRATE(float temp);

private:
    uint8_t ledPin;
    unsigned long toggletime = 0;
    bool ledState = LOW;
    unsigned long timebetweenblinks = 1000;
};

using LEDControllerInstance = etl::singleton<LEDController>;