#include "M5_DLight.h"

M5_DLight::M5_DLight(uint8_t addr) {
    _addr = addr;
}

/*! @brief Initialize the EXTIO2.*/
void M5_DLight::begin(TwoWire *wire, uint8_t sda, uint8_t scl, uint32_t freq) {
    _wire = wire;
    _sda  = sda;
    _scl  = scl;
    _freq = freq;
    _wire->begin((int)_sda, (int)_scl, _freq);
    powerOn();
}

/*! @brief Write data to the register address. */
void M5_DLight::writeByte(byte cmd) {
    _wire->beginTransmission(_addr);
    _wire->write(cmd);
    _wire->endTransmission();
}

/*! @brief Write the specified length of data to the register.*/
void M5_DLight::writeBytes(uint8_t *buffer, size_t size) {
    _wire->beginTransmission(_addr);
    _wire->write(buffer, size);
    _wire->endTransmission();
}

/*! @brief Read a certain length of data to the specified register address.*/
void M5_DLight::readBytes(uint8_t *buffer, size_t size) {
    _wire->requestFrom(_addr, size);
    for (uint16_t i = 0; i < size; i++) {
        buffer[i] = _wire->read();
    }
}

/*! @brief Reading light intensity.
    @return Light intensity value read.. */
uint16_t M5_DLight::getLUX() {
    uint16_t lux;
    uint8_t buffer[2];
    readBytes(buffer, 2);
    lux = buffer[0] << 8 | buffer[1];
    return lux;
}

/*! @brief Turn on the power.*/
void M5_DLight::powerOn() {
    writeByte(POWER_ON);
}

/*! @brief Turn off the power.*/
void M5_DLight::powerOff() {
    writeByte(POWER_DOWN);
}

/*! @brief Set the mode.*/
void M5_DLight::setMode(byte mode) {
    writeByte(mode);
}
