#include <Arduino.h>
#include "pin_define.h"

void init() {

  Serial.begin(115200);
  
  //LED
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  //TOUCH PAD

}

void setup() {
  init();

}

void loop() {
  //delay(1000);

  //Serial.println("----------" + String(millis()) + "----------");
  //Serial.println(digitalRead(PIN_TOUCH_PAD));
}