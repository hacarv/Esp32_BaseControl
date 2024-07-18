#include "WiFiConnection.h"
#include <WiFi.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setupWiFi() {
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("ESP32-AP", "12345678");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

