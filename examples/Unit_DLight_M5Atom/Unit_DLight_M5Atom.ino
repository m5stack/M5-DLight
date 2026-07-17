/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with Atom-Lite/Matrix sample source code
*                          配套  Atom-Lite/Matrix 示例源代码
* Visit for more information: https://docs.m5stack.com/en/unit/dlight
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/dlight
*
* Product: Unit DLight
* Date: 2026/7/17
*******************************************************************************
  Please connect the sensor to port, the Lux value will be output
  on the serial after successful initialization
  请将传感器连接至端口, 成功初始化后串口上将输出Lux数值
*/

#include <M5Unified.h>
#include <M5_DLight.h>
// Install the Adafruit NeoPixel library:
// https://github.com/adafruit/Adafruit_NeoPixel
#include <Adafruit_NeoPixel.h>

#define LED_PIN 27
#define NUM_LEDS 25

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

M5_DLight sensor;
uint16_t lux;

void setup()
{
    M5.begin();
    Serial.begin(115200);
    Serial.println("Sensor begin.....");
    sensor.begin(&Wire, 26, 32);
    strip.begin();

    // CONTINUOUSLY_H_RESOLUTION_MODE
    // CONTINUOUSLY_H_RESOLUTION_MODE2
    // CONTINUOUSLY_L_RESOLUTION_MODE
    // ONE_TIME_H_RESOLUTION_MODE
    // ONE_TIME_H_RESOLUTION_MODE2
    // ONE_TIME_L_RESOLUTION_MODE
    sensor.setMode(CONTINUOUSLY_H_RESOLUTION_MODE);
}

void loop()
{
    for (char i = 0; i <= NUM_LEDS; i++)
    {
        strip.setPixelColor(i, strip.Color(0, 255, 0));
    }
    strip.show();
    lux = sensor.getLUX();
    Serial.printf("lux: %d\n", lux);
    delay(200);
}
