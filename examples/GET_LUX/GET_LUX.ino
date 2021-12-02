
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

  //CONTINUOUSLY_H_RESOLUTION_MODE
  //CONTINUOUSLY_H_RESOLUTION_MODE2
  //CONTINUOUSLY_L_RESOLUTION_MODE
  //ONE_TIME_H_RESOLUTION_MODE
  //ONE_TIME_H_RESOLUTION_MODE2
  //ONE_TIME_L_RESOLUTION_MODE
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