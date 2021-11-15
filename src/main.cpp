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

  wifi_init();
  delay(500);
  mqtt_init();
  delay(500);
}

void setup() {
  init();
}

void loop() {
  Serial.println("WakeUp");
  deep_sleep = true;



  if(millis() - loop_temp_time >= 100)
  {
    Serial.println("Deepsleep");
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, HIGH);
    esp_deep_sleep_start();
  }

    bat_show();
    mpu_show();
    if(!wifi_stat()){
      Serial.println("wifi not connected");
      wifi_init();
      delay(500);
    }
    mqttpub();
  }
}