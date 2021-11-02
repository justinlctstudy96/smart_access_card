#include "pin_define.h"

#include "adc_bat.h"
#include "driver_tft.h"
#include "driver_mpu.h"
// #include "bluetooth.h"
#include "wifi_c.h"
#include "mqtt.h"

u_long loop_temp_time;

bool deep_sleep;

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

  // wifi_init();
  // mqtt_init();
}

void setup() {
  init();
}

void loop() {
  Serial.println("WakeUp");
  deep_sleep = true;

  if(deep_sleep == true)
  {
    Serial.println("Deepsleep");
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, HIGH);
    esp_deep_sleep_start();
  }




  // if(millis() - loop_temp_time >= 100)
  // {
  //   loop_temp_time = millis();
  //   Serial.println("----------" + String(millis()) + "----------");

  //   //tft_show();
  //   //bat_show();
  //   //mpu_show();
  //   Serial.println(digitalRead(PIN_MPU_INT));
  // }
}