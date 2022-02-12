#include "messenger.h"
#include <Arduino.h>

void Messenger::Logger(String msg) {
  Serial.print("[DEBUG]: ");
  //Serial.print(millis());
  //Serial.print("ms]: ");
  Serial.println(msg);
}

void Messenger::Logger(String msg[]) {
  size_t length = sizeof(msg);
  String std = msg[0];
  for (size_t i = 1; i < length; i++) {
    std += msg[i];
  }
  Logger(std);
}