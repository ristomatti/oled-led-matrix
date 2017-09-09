# oled-led-matrix

Code to control ESP8266 with 64x48 OLED and 8x8 LED matrix displays through MQTT.

## Configuration

### Template: src/config.h

```c
const char *wifiSsid = "";
const char *wifiPassword = "";

const char *mqttHost = "";
const char *mqttUser = "";
const char *mqttPassword = "";

const char *statusTopic = "esp8266/status";
const char *ledTopic = "esp8266/led/set";
const char *oledTopic = "esp266/oled/set";
```
