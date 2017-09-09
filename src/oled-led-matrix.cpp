#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SimpleTimer.h>
#include "oled.h"
#include "led.h"
#include "buzzer.h"
#include "config.h"

void callback(char *topic, byte *payload, unsigned int length);
void mqttPublished(void *response);
String macToStr(const uint8_t *mac);

WiFiClient wifiClient;
PubSubClient mqtt(mqttHost, 1883, callback, wifiClient);
SimpleTimer timer;

void setup() {
  Serial.begin(115200);

  ledSetup();
  oledSetup();
  buzzerSetup();

  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifiSsid);

  WiFi.begin(wifiSsid, wifiPassword);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Generate client name based on MAC address and last 8 bits of microsecond counter
  String clientName;
  clientName += "node2-";
  uint8_t mac[6];
  WiFi.macAddress(mac);
  clientName += macToStr(mac);
  clientName += "-";
  clientName += String(micros() & 0xff, 16);

  Serial.print("Connecting to ");
  Serial.print(mqttHost);
  Serial.print(" as ");
  Serial.println(clientName);

  if (mqtt.connect((char *)clientName.c_str(), mqttUser, mqttPassword, statusTopic, 1, true, "offline")) {
    Serial.println("Connected to MQTT broker");
    Serial.print("Topic is: ");
    Serial.println(statusTopic);

    mqtt.subscribe(ledTopic);
    mqtt.subscribe(oledTopic);

    if (mqtt.publish(statusTopic, "online", true)) {
      Serial.println("Publish ok");
    } else {
      Serial.println("Publish failed");
    }
  } else {
    Serial.println("MQTT connect failed");
    Serial.println("Will reset and try again...");
    abort();
  }
}

void loop() {
  timer.run();

  mqtt.loop();
  oledLoop();
  ledLoop();
  buzzerLoop();
}

void callback(char *topic, byte *payload, unsigned int length) {
  payload[length] = '\0';
  String data = String((char *)payload);
  Serial.print(topic);
  Serial.print(":\t");
  Serial.println(data);
}

void mqttPublished(void *response) {}

String macToStr(const uint8_t *mac) {
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5) result += ':';
  }
  return result;
}
