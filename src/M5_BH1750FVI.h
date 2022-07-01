#ifndef __M5_BH1750FVI_H__
#define __M5_BH1750FVI_H__

#include "Arduino.h"
#include "Wire.h"
#include "pins_arduino.h"

#define DEVICE_I2C_ADDR 0x23

// CMD
#define POWER_DOWN                      B00000000
#define POWER_ON                        B00000001
#define RESET                           B00000111
#define CONTINUOUSLY_H_RESOLUTION_MODE  B00010000
#define CONTINUOUSLY_H_RESOLUTION_MODE2 B00010001
#define CONTINUOUSLY_L_RESOLUTION_MODE  B00010011
#define ONE_TIME_H_RESOLUTION_MODE      B00100000
#define ONE_TIME_H_RESOLUTION_MODE2     B00100001
#define ONE_TIME_L_RESOLUTION_MODE      B00100011

class M5_BH1750FVI {
   private:
    TwoWire *_wire;
    uint8_t _sda;
    uint8_t _scl;
    uint32_t _freq;
    uint8_t _addr;
    void writeByte(byte cmd);
    void writeBytes(uint8_t *buffer, size_t size);
    void readBytes(uint8_t *buffer, size_t size);

   public:
    M5_BH1750FVI(uint8_t addr = 0x23);
    void begin(TwoWire *wire = &Wire, uint8_t sda = SDA, uint8_t scl = SCL,
               uint32_t freq = 4000000UL);

    void powerOn();
    void powerOff();
    void powerReset();
    void setMode(byte mode);
    uint16_t getLUX();
};

#endif