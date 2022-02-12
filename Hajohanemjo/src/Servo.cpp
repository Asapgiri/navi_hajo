#include "pwmServo.h"
#include "shipProject.h"

ServoControll::ServoControll(Stream *serial, int _servo_pin, int _offset, bool _reverse) : Ship(serial) {
  if (__DEBUG) Messenger::Logger("Initialise class: ServoControll");
  this->servo_pin = _servo_pin;
  this->reverse = _reverse;
  this->degree = _offset;
  this->offset = _offset;
  servo.attach(this->servo_pin);
  if (__DEBUG) {
    String std[] = {"Servo: initialized with offset: ", String(_offset), "deg"};
    Messenger::Logger(std);
  }
}

// TODO: Needs debug because quits loop on commented for secont time...
void ServoControll::RotateToDegree(int deg) {
  if (deg > 75) deg = 75;
  else if (deg < -75) deg = -75;

  if (__DEBUG) {
    String std[] = {"Servo: Rotating to ", String(deg), "deg"};
    Messenger::Logger(std);
  }
  degree = deg;
  if (this->reverse) servo.write(this->offset-deg);
  else servo.write(this->offset+deg);
}

uint8_t ServoControll::getDegree() {
  return degree;
}