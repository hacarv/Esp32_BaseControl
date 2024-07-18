#include "WebSocketHandler.h"
#include <ArduinoJson.h>
#include "LED.h"
#include "ServoMotor.h"
#include "StepperMotor.h"

extern LED led;
extern ServoMotor servoMotor;
extern StepperMotor stepperMotor;

AsyncWebSocket *wsServer;

void notifyClients(const String& message) {
    wsServer->textAll(message);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    String message = (char *)data;
   JsonDocument doc;
    deserializeJson(doc, message);
    if (doc.containsKey("led")) {
      led.setColor(doc["led"]["r"], doc["led"]["g"], doc["led"]["b"]);
    }
    if (doc.containsKey("servo")) {
      servoMotor.setPosition(doc["servo"]);
    }
    if (doc.containsKey("stepper")) {
      stepperMotor.moveSteps(doc["stepper"]);
    }
  }
}

void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  wsServer = server;
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

