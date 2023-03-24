/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with M5Core sample source code
*                          配套  M5Core 示例源代码
* Visit for more information: https://docs.m5stack.com/en/unit/dlight
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/dlight
*
* Describe: Ambient light detection BH1750FVI
* Date: 2023/3/24
*******************************************************************************
  Please connect the sensor to port A (22, 21), the Lux value will be displayed
  on the display after successful initialization
  请将传感器连接至端口A(22、21),成功初始化后显示屏上将显示Lux数值
  hp_BH1750.h Please download the file from the library management office
  hp_BH1750.h 文件请从库管理处下载
*/

#include <M5Stack.h>
#include <M5GFX.h>

#include <hp_BH1750.h>  //  include the library
hp_BH1750 BH1750;       //  create the sensor

M5GFX display;
M5Canvas canvas(&display);

void setup() {
    bool avail =
        BH1750.begin(BH1750_TO_GROUND);  // init the sensor with address pin
                                         // connetcted to ground result (bool)
                                         // wil be be "false" if no sensor found
    if (!avail) {
        Serial.println("No BH1750 sensor found!");
        while (true) {
        };
    }

    M5.begin();
    display.begin();
    canvas.setTextDatum(MC_DATUM);
    canvas.setColorDepth(1);
    canvas.setFont(&fonts::Orbitron_Light_24);
    canvas.setTextSize(2);
    canvas.createSprite(display.width(), display.height());
    canvas.setPaletteColor(1, ORANGE);
    Serial.println("Sensor begin.....");
}

char info[40];

void loop() {
    // put your main code here, to run repeatedly:
    BH1750.start();                  // starts a measurement
    uint16_t lux = BH1750.getLux();  //  waits until a conversion finished
    sprintf(info, "lux: %d", lux);

    canvas.fillSprite(BLACK);
    canvas.drawString(info, 160, 120);
    canvas.pushSprite(0, 0);
    Serial.println(info);
    delay(100);
}
