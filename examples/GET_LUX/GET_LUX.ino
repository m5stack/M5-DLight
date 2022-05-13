/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information：https://docs.m5stack.com/en/hat/hat_dlight
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/hat/hat_dlight
*
* describe：lux.
* date：2022/5/13
*******************************************************************************
*/
#include <M5StickC.h>
#include <M5_BH1750FVI.h>

TFT_eSprite canvas(&M5.Lcd);

M5_BH1750FVI sensor;
uint16_t lux;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(1);
    canvas.setTextColor(GREEN);
    canvas.setTextDatum(MC_DATUM);
    canvas.setTextSize(2);
    canvas.createSprite(160, 80);
    Serial.println("Sensor begin.....");
    sensor.begin();

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