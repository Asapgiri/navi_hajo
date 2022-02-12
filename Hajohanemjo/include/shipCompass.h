#ifndef SHIP_COMPASS
#define SHIP_COMPASS

#include "MPU9250.h"
#include "messenger.h"
#include <Arduino.h>

class Compass {
  private:
    MPU9250 mpu;
  public:
    Compass();
    String serialize();
    void log();
};

#endif