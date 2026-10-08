#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"

float BMESPIInterface::getTemp()
{
    return bme.readTemperature();
}

bool BMESPIInterface::begin()
{
    return bme.begin();
}