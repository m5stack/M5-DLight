#include "M5_BH1750FVI.h"

M5_BH1750FVI::M5_BH1750FVI(uint8_t addr) {
    _addr = addr;
}

void M5_BH1750FVI::writeByte(byte cmd) {
    _wire->beginTransmission(_addr);
    _wire->write(cmd);
    _wire->endTransmission();
}

void M5_BH1750FVI::writeBytes(uint8_t *buffer, size_t size) {
    _wire->beginTransmission(_addr);
    _wire->write(buffer, size);
    _wire->endTransmission();
}

void M5_BH1750FVI::readBytes(uint8_t *buffer, size_t size) {
    _wire->requestFrom(_addr, size);
    for(uint16_t i = 0; i < size; i++){
        buffer[i] = _wire->read();
    }
}

uint16_t M5_BH1750FVI::getLUX() {
    uint16_t lux;
    uint8_t buffer[2];
    readBytes(buffer, 2);
    lux = buffer[0] << 8 | buffer[1];
    return lux;
}

void M5_BH1750FVI::begin(
    TwoWire *wire,
    uint8_t sda, 
    uint8_t scl, 
    uint32_t freq
) {
    _wire = wire;
    _sda = sda;
    _scl = scl;
    _freq = freq;
    _wire->begin(_sda, _scl, _freq);
    powerOn();
}

void M5_BH1750FVI::powerOn() {
    writeByte(POWER_ON);
}

void M5_BH1750FVI::powerOff() {
    writeByte(POWER_DOWN);
}

void M5_BH1750FVI::setMode(byte mode) {
    writeByte(mode);
}
