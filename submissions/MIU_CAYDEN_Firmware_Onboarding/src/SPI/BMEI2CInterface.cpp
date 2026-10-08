#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BMEI2CInterface.h"

float BMEI2CInterface::getTemp()
{
    return bme.readTemperature();
}

bool BMEI2CInterface::begin()
{
    return bme.begin(BMEConstants::BME_I2C_ADDRESS);
}