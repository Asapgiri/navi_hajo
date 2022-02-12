#ifndef SHIP_WIFI
#define SHIP_WIFI

#include "shipProject.h"
#include <ArduinoJson.h>

class Wifi : public Ship {
  private:
    Motors *motors;
    ServoControll *servo;
    Compass *compass;
    Gps *gps;
    Transists *transists;
    String message = "";
    bool messageReady = false;
    
  public:
    Wifi(Stream *serial, Motors *_motors, ServoControll *_servo, Compass *_compass, Gps *_gps, Transists *_transists);
    void HandleRequest();
};

#endif