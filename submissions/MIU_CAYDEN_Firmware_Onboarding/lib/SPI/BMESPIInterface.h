#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() : bme(BMEConstants::BME_CS) {}
    bool begin();
    float getTemp();

private:
    Adafruit_BME280 bme;
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;