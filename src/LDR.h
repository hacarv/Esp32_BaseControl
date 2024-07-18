#ifndef LDR_H
#define LDR_H

class LDR {
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
