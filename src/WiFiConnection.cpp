#include <WiFi.h>
#include "WiFiConnection.h"
#include "config.h"

void setupWiFi() {
    WiFi.mode(WIFI_AP_STA);

    // Station Mode
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Access Point Mode
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    Serial.println("Access Point started");
    Serial.print("AP IP Address: ");
    Serial.println(WiFi.softAPIP());
}

