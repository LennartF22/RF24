/**
 * @file spi.h
 * Class declaration for SPI helper files
 *
 * See https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/spi_master.html
 */
#ifndef RF24_UTILITY_ESP_IDF_SPI_H_
#define RF24_UTILITY_ESP_IDF_SPI_H_

#include <stdint.h> // uintXX_t
#include <driver/spi_master.h>
#include <freertos/semphr.h>

#ifndef RF24_SPI_SPEED
    #define RF24_SPI_SPEED 10000000
#endif

#ifdef CONFIG_RF24_DEFAULT_SPI_BUS
    #define DEFAULT_SPI_BUS CONFIG_RF24_DEFAULT_SPI_BUS
#else
    #define DEFAULT_SPI_BUS SPI2_HOST
#endif

#define SPI_HAS_TRANSACTION

enum esp_spi_mode_t : uint8_t
{
    ESP_SPI_MODE0 = 0,
    ESP_SPI_MODE1 = 1,
    ESP_SPI_MODE2 = 2,
    ESP_SPI_MODE3 = 3,
};

class ESPSPIClass
{

public:
    ESPSPIClass();

    void begin(spi_host_device_t busNo = DEFAULT_SPI_BUS, uint32_t speed = RF24_SPI_SPEED);
    void begin(spi_host_device_t busNo, uint32_t speed, uint8_t mode, spi_bus_config_t* busConfig);
    void begin(spi_device_handle_t dev);

    void beginTransaction();

    void endTransaction();

    void transfernb(const uint8_t* txBuf, uint8_t* rxBuf, uint32_t len);

    void transfern(const uint8_t* buf, uint32_t len);

    virtual ~ESPSPIClass();

private:
    /** SPI bus handle: A pointer to the allocated SPI device as initialized in begin() */
    spi_device_handle_t bus;

    SemaphoreHandle_t lock;
};

#endif // RF24_UTILITY_ESP_IDF_SPI_H_
