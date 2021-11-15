#include "mqtt.h"

WiFiClient espClient;
PubSubClient mqttclient(espClient);
const char* mqtt_server = "18.162.55.224";
uint16_t mqtt_port = 9000;
String s=";";
int id = 0;


void mqtt_init(){
    mqttclient.setServer(mqtt_server, mqtt_port);
    mqttclient.connect("smart_acces_card");
}



void mqttpub(){
  if (!mqttclient.connected()) {
    Serial.println("mqtt broker not connected. Reconnecting ...");
    mqttclient.connect("smart_acces_card");
    delay(500);
  }
  else{
    // String data = String(x)+", "+String(y)+", "+String(z);
    // mqttclient.publish("/watch", data.c_str());
    String data = String(ax)+", "+String(ay)+", "+String(az)+", "+String(gx)+", "+String(gy)+", "+String(gz)+", "+String(mx)+", "+String(my)+", "+String(mz);
    mqttclient.publish("/nine", data.c_str());
    Serial.println("published");
  }
}