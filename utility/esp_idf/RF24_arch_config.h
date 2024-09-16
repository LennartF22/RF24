/**
 * @file RF24_arch_config.h
 * General defines and includes for RF24 on ESP-IDF platform
 */
#ifndef RF24_UTILITY_ESP_IDF_RF24_ARCH_CONFIG_H_
#define RF24_UTILITY_ESP_IDF_RF24_ARCH_CONFIG_H_

#define RF24_ESP_IDF

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdint.h> // uintXX_t
#include <stdio.h>  // printf(), sprintf()
#include <string.h> // memcpy() used in RF24.cpp, strlen()
#include <unistd.h> // usleep()

#define _BV(x) (1 << (x))
#endif

#include "spi.h"

#define _SPI   ESPSPIClass
#define RF24_SPI_PTR

#ifdef RF24_DEBUG
    #define IF_RF24_DEBUG(x) ({ x; })
#else
    #define IF_RF24_DEBUG(x)
#endif

#ifdef ARDUINO
#include <pgmspace.h> // necessary?
#else
typedef uint16_t prog_uint16_t;
#define PSTR(x)  (x)
#define printf_P printf
#define sprintf_P sprintf
#define strlen_P strlen
#define PROGMEM
#define PRIPSTR  "%s"
#define pgm_read_word(p) (*(const unsigned short*)(p))
#define pgm_read_byte(p) (*(const unsigned char*)(p))
#define pgm_read_ptr(p)  (*(void* const*)(p))
#endif

#ifdef ARDUINO
typedef uint8_t rf24_gpio_pin_t;
#define RF24_PIN_INVALID 0xFF
#else
#include "gpio.h"
#include "compatibility.h"

// Function, constant map as a result of migrating from Arduino
#define LOW                      GPIO::OUTPUT_LOW
#define HIGH                     GPIO::OUTPUT_HIGH
#define INPUT                    GPIO::DIRECTION_IN
#define OUTPUT                   GPIO::DIRECTION_OUT
#define digitalWrite(pin, value) GPIO::write(pin, value)
#define pinMode(pin, direction)  GPIO::open(pin, direction)
#define delay(milisec)           __msleep(milisec)
#define delayMicroseconds(usec)  usleep(usec)
#define millis()                 __millis()
#endif

#endif // RF24_UTILITY_ESP_IDF_RF24_ARCH_CONFIG_H_
