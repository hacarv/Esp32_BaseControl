#ifndef CONFIG_H
#define CONFIG_H

// WiFi configuration
#define SSID "your_SSID"
#define PASSWORD "your_PASSWORD"

// Access Point configuration
#define AP_SSID "ESP32_AP"
#define AP_PASSWORD "your_AP_PASSWORD"

// Pin configuration
#define LDR_PIN 34
#define LED_PIN 5
#define SERVO_PIN 18
#define POTENTIOMETER_PIN 32
#define STEPPER_PIN1 19
#define STEPPER_PIN2 21
#define STEPPER_PIN3 22
#define STEPPER_PIN4 23

// JSON Keys
#define LDR_KEY "ldr"
#define LED_KEY "led"
#define SERVO_KEY "servo"
#define POTENTIOMETER_KEY "potentiometer"
#define STEPPER_KEY "stepper"
#define ERROR_KEY "error"

#endif // CONFIG_H
