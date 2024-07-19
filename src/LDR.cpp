#include "LDR.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "WebSocketHandler.h"
#include "config.h"

void LDR::begin(int pin) {
    _pin = pin;
    _lastValue = -1;
    pinMode(_pin, INPUT);
}

int LDR::read() {
    return analogRead(_pin);
}

void LDR::readAndNotify(unsigned long currentTime) {
    int value = read();
    if (value != _lastValue) {
        _lastValue = value;
       JsonDocument doc;
       doc[LDR_KEY] = value;
        String jsonString;
        serializeJson(doc, jsonString);
        notifyClients(jsonString);
    }
}

bool LDR::isConnected() {
    return analogRead(_pin) != -1; // Dummy check, replace with actual connection check if needed
}
