#pragma once

#include "RF24_config.h"

class RF24_hal
{
public:
    virtual void ce(bool level) = 0;
    virtual uint8_t read(uint8_t cmd, uint8_t* buf, uint8_t len) = 0;
    virtual uint8_t read(uint8_t cmd, uint8_t* buf, uint8_t data_len, uint8_t blank_len) = 0;
    virtual uint8_t write(uint8_t cmd, const uint8_t* buf, uint8_t len) = 0;
    virtual uint8_t write(uint8_t cmd, const uint8_t* buf, uint8_t len, uint8_t blank_len) = 0;
    virtual bool begin() = 0;
    virtual void end() = 0;
};
