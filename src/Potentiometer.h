#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer {
public:
    void begin(int pin);
    int read();
    void readAndNotify(unsigned long currentTime);
    bool isConnected();
private:
    int _pin;
    int _lastValue;
};

#endif
