/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information: http://docs.m5stack.com/en/hat/hat_dlight
* 获取更多资料请访问: http://docs.m5stack.com/zh_CN/hat/hat_dlight
*
* Product: Hat DLight.
* Date: 2026/7/17
*******************************************************************************
  Measure and output light intensity on screen and serial port
  测量并在屏幕和串口输出光照强度
*/

#include <M5Unified.h>
#include <M5_DLight.h>

M5Canvas canvas(&M5.Display);

M5_DLight sensor;
uint16_t lux;

void setup() {
    M5.begin();
    M5.Display.setRotation(3);
    canvas.setTextDatum(MC_DATUM);
    canvas.setColorDepth(1);
    canvas.setFont(&fonts::Orbitron_Light_24);
    canvas.setTextSize(1);
    canvas.createSprite(M5.Display.width(), M5.Display.height());
    canvas.setPaletteColor(1, ORANGE);
    Serial.begin(115200);
    Serial.println("Sensor begin.....");
    sensor.begin(&Wire, 0, 26);  // HAT DLight

    // CONTINUOUSLY_H_RESOLUTION_MODE
    // CONTINUOUSLY_H_RESOLUTION_MODE2
    // CONTINUOUSLY_L_RESOLUTION_MODE
    // ONE_TIME_H_RESOLUTION_MODE
    // ONE_TIME_H_RESOLUTION_MODE2
    // ONE_TIME_L_RESOLUTION_MODE
    sensor.setMode(CONTINUOUSLY_H_RESOLUTION_MODE);
}

char info[40];

void loop() {
    lux = sensor.getLUX();
    sprintf(info, "lux: %d", lux);
    canvas.fillSprite(BLACK);
    canvas.drawString(info, 80, 40);
    canvas.pushSprite(0, 0);
    Serial.println(info);
    delay(100);
}
