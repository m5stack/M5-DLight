/*!
 * @brief A Digital Ambient Light Sensor From M5Stack
 * @copyright Copyright (c) 2026 by M5Stack[https://m5stack.com]
 *
 * @Links [Unit DLight](https://docs.m5stack.com/en/unit/dlight)
 * @Links [HAT DLight](https://docs.m5stack.com/en/hat/hat_dlight)
 * @version  V0.0.5
 * @date  2026-04-21
 */
#ifndef _M5_DLIGHT_H_
#define _M5_DLIGHT_H_

#include "Arduino.h"
#include "Wire.h"
#include "pins_arduino.h"

#define DEVICE_I2C_ADDR 0x23

// CMD
#define POWER_DOWN                      0b00000000
#define POWER_ON                        0b00000001
#define RESET                           0b00000111
#define CONTINUOUSLY_H_RESOLUTION_MODE  0b00010000
#define CONTINUOUSLY_H_RESOLUTION_MODE2 0b00010001
#define CONTINUOUSLY_L_RESOLUTION_MODE  0b00010011
#define ONE_TIME_H_RESOLUTION_MODE      0b00100000
#define ONE_TIME_H_RESOLUTION_MODE2     0b00100001
#define ONE_TIME_L_RESOLUTION_MODE      0b00100011

class M5_DLight {
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
    M5_DLight(uint8_t addr = 0x23);
    void begin(TwoWire *wire = &Wire, uint8_t sda = SDA, uint8_t scl = SCL, uint32_t freq = 400000UL);

    void powerOn();
    void powerOff();
    void setMode(byte mode);
    uint16_t getLUX();
};

#endif
