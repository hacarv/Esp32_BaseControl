#include "Potentiometer.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "WebSocketHandler.h"
#include "config.h"

void Potentiometer::begin(int pin) {
    _pin = pin;
    _lastValue = -1;
    pinMode(_pin, INPUT);
}

int Potentiometer::read() {
    return analogRead(_pin);
}

void Potentiometer::readAndNotify(unsigned long currentTime) {
    int value = read();
    if (value != _lastValue) {
        _lastValue = value;
        JsonDocument doc;
        doc[POTENTIOMETER_KEY] = value;
        String jsonString;
        serializeJson(doc, jsonString);
        notifyClients(jsonString);
    }
}

bool Potentiometer::isConnected() {
    return analogRead(_pin) != -1; // Dummy check, replace with actual connection check if needed
}

