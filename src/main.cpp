#include "pin_define.h"

#include "adc_bat.h"
//#include "driver_tft.h"
#include "driver_mpu.h"
// #include "bluetooth.h"
#include "wifi_c.h"
#include "mqtt.h"

u_long loop_temp_time;

void init() {

  Serial.begin(115200);
  // bluetooth_init();
  //LED
  //pinMode(PIN_LED, OUTPUT);
  //digitalWrite(PIN_LED, LOW);

  //BAT
  bat_init();
  //TFT
  //tft_init();
  //MPU
  mpu_init();

  wifi_init();
  mqtt_init();
}

void setup() {
  init();
}

void loop() {

  if(millis() - loop_temp_time >= 1000)
  {
    loop_temp_time = millis();
    Serial.println("----------" + String(millis()) + "----------");

    bat_show();
    mpu_show();

    mqttpub();
  }
}