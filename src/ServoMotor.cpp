#include "ServoMotor.h"

void ServoMotor::begin(int pin) {
    _servo.attach(pin);
    _position = 0;
}

void ServoMotor::setPosition(int position) {
    _position = position;
    _servo.write(_position);
}

void ServoMotor::update() {
    // No-op
}

bool ServoMotor::isConnected() {
    return _servo.attached();
}

