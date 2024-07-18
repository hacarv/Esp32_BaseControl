#include "LED.h"

void LED::begin() {
    _strip = Adafruit_NeoPixel(1, 4, NEO_GRB + NEO_KHZ800);
    _strip.begin();
    _strip.show();
    _color = 0;
}

void LED::setColor(uint8_t r, uint8_t g, uint8_t b) {
    _color = _strip.Color(r, g, b);
    _strip.setPixelColor(0, _color);
    _strip.show();
}

void LED::update() {
    // No-op
}

bool LED::isConnected() {
    return _strip.numPixels() > 0; // Dummy check, replace with actual connection check if needed
}

