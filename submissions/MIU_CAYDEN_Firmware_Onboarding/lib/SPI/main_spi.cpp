#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using namespace std;
bool start = false;
auto &spi = BMESPIInterfaceInstance::instance();
float currentTemperature;

void setup()
{
    // Code here!
    start = spi.begin();
    if (start)
    {
        Serial.print("READY");
    }
    else
    {
        Serial.print("NOT READY");
    }
}

void loop()
{
    float currentTemp = BMESPIInterfaceInstance::instance().getTemp();
    LEDControllerInstance::instance().updateTemp(currentTemp);
    Serial.print("SPI Temperature: ");
    Serial.print(currentTemp);
    Serial.println(" °C");
}