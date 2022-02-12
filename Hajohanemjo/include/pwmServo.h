#ifndef SHIP_SERVO
#define SHIP_SERVO

#include <Arduino.h>
#include "Ship.h"
#include "servo.h"

class ServoControll : public Ship {
  private:
    uint8_t degree;
    uint8_t offset; // 0degree
    int servo_pin;
    bool reverse;
    Servo servo;
  public:
    ServoControll(Stream *serial, int _servo_pin, int _offset, bool _reverse = false);
    void RotateToDegree(int deg); //-75 - +75 ~~
    uint8_t getDegree();
};

#endif