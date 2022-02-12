#include "shipWifi.h"

Wifi::Wifi(Stream *serial, Motors *_motors, ServoControll *_servo, Compass *_compass, Gps *_gps, Transists *_transists) : Ship(serial) {
  this->compass = _compass;
  this->gps = _gps;
  this->motors = motors;
  this->servo = _servo;
  this->transists = _transists;
}

void Wifi::HandleRequest() {
  while (_serial->available()) {
    message = _serial->readStringUntil('\n');
    messageReady = true;
  }
  // Only process message if there's one
  if(messageReady) {
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc,message);
    if(error) {
      doc["type"] = F("error");
      doc["desc"] = F("deserializeJson() failed");
      doc["msg"] = error.c_str();
      //serializeJson(doc, _serial);
      _serial->print("ERROR: ");
      _serial->println(error.c_str());
      messageReady = false;
      return;
    }
    if(doc["type"] == "request") {
      //doc["type"] = "response";
      // Get data from analog sensors
      //if (motors) doc["motors"] = motors->serialize();
      //if (servo) doc["servo"] = servo->getDegree();
      //if (compass) doc["compass"] = compass->serialize();
      //if (gps) doc["gps"] = gps->serialize();
      //if (transists) doc["transists"] = transists->serialize();
      //serializeJson(doc,*_serial);
      //serializeJson(doc,Serial);

      String json = "{\"type\":\"response\"";
      //json += ",\"motors\":"; if (motors) json += motors->serialize(); else json += "\"N/A\"";
      json += ",\"servo\":"; if (servo) { json += "\"" + servo->getDegree(); json += "\""; } else json += "\"N/A\"";
      json += ",\"compass\":"; if (compass) json += compass->serialize(); else json += "\"N/A\"";
      json += ",\"gps\":"; if (gps) json += gps->serialize(); else json += "\"N/A\"";
      //json += ",\"transists\":"; if (transists) json += transists->serialize(); else json += "\"N/A\"";
      json += "}";
      _serial->println(json);
    }
    else if (doc["type"] == "data_set") {
      if (motors) {
        motors->setRightMotorSpeed(doc["leftSpeed"]);
        motors->setLeftMotorSpeed(doc["rightSpeed"]);
      }
      if (servo) servo->RotateToDegree(doc["servo"]);
      _serial->println("OK.");
      //serializeJson(doc,Serial);
      //Serial.println();
    }
    else if (doc["type"] == "auto_data") {
      _serial->println("OK.");
      Serial.println(message);
    }
    if (__DEBUG) Serial.println(message);
    messageReady = false;
  }
}