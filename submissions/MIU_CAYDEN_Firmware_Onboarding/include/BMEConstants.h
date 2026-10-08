#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // using unit8_t and int8_t for pin numbers to save memory
    constexpr uint8_t LED_PIN = LED_BUILTIN;  // uses built in LED pin
    constexpr int8_t BME_CS = 10;             // chip select pin for spi
    constexpr uint8_t BME_I2C_ADDRESS = 0x76; // i2c address for bme280
}