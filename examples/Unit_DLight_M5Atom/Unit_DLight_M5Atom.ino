/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with Atom-Lite/Matrix sample source code
*                          配套  Atom-Lite/Matrix 示例源代码
* Visit for more information: https://docs.m5stack.com/en/unit/dlight
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/dlight
*
* Product: Unit DLight
* Date: 2023/05/29
*******************************************************************************
  Please connect the sensor to port, the Lux value will be output
  on the serial after successful initialization
  请将传感器连接至端口, 成功初始化后串口上将输出Lux数值
*/

#include <M5Atom.h>
#include <M5_DLight.h>

M5_DLight sensor;
uint16_t lux;

void setup() {
    M5.begin(true, true, true);
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

void loop() {
    M5.dis.fillpix(0x00ff00);
    lux = sensor.getLUX();
    Serial.printf("lux: %d\n", lux);
    delay(200);
}
