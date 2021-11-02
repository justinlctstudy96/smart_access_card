#include "mqtt.h"

WiFiClient espClient;
PubSubClient mqttclient(espClient);
const char* mqtt_server = "218.253.145.198";
uint16_t mqtt_port = 31001;
String s=";";

void mqtt_init(){
    mqttclient.setServer(mqtt_server, mqtt_port);
    mqttclient.connect("watch");
}

void mqttpub(){
  if (!mqttclient.connected()) {
    Serial.println("mqtt broker not connected. Reconnecting ...");
    mqttclient.connect("smart_acces_card");
  }
  else{
    String data = String(x)+", "+String(y)+", "+String(z);
    mqttclient.publish("/watch/data", data.c_str());
  }
}