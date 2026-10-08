#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using namespace std;
bool start = false;
auto &i2c = BMEI2CInterfaceInstance::instance();
float currentTemperature;

void setup()
{
    // Code here!
    start = i2c.begin();
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
    float currentTemp = BMEI2CInterfaceInstance::instance().getTemp();
    LEDControllerInstance::instance().updateTemp(currentTemp);
    Serial.print("I2C Temperature: ");
    Serial.print(currentTemp);
    Serial.println(" °C");
}