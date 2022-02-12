#ifndef SHIP_MOTORS
#define SHIP_MOTORS

#include "definer.h"
#include <Arduino.h>

class Motors {
  private:
    int8_t leftSpeed;
    int8_t rightSpeed;
    void setMotors();
  public:
    Motors();
    void setMotorSpeeds(int speed);
    void setLeftMotorSpeed(int speed);
    void setRightMotorSpeed(int speed);
    int getLeftSpeed();
    int getRightSpeed();
    String serialize();
};

#endif