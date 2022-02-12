#include "pwmMotor.h"

Motors::Motors() {
  analogWrite(MOTOR_PWM_A1_PIN, 0);
  analogWrite(MOTOR_PWM_A2_PIN, 0);
  analogWrite(MOTOR_PWM_B1_PIN, 0);
  analogWrite(MOTOR_PWM_B2_PIN, 0);
}

void Motors::setLeftMotorSpeed(int speed) {
  if (speed > 100) speed = 100;
  else if (speed < -100) speed = -100;
  this->leftSpeed = speed;

  if (speed >= 0) {
    analogWrite(MOTOR_PWM_A2_PIN, 0);
    analogWrite(MOTOR_PWM_A1_PIN, (int)((float)speed*2.55));
  }
  else {
    speed = -speed;
    analogWrite(MOTOR_PWM_A1_PIN, 0);
    analogWrite(MOTOR_PWM_A2_PIN, (int)((float)speed*2.55));
  }
}

void Motors::setRightMotorSpeed(int speed) {
  if (speed > 100) speed = 100;
  else if (speed < -100) speed = -100;
  this->rightSpeed = speed;

  if (speed >= 0) {
    analogWrite(MOTOR_PWM_B2_PIN, 0);
    analogWrite(MOTOR_PWM_B1_PIN, (int)((float)speed*2.55));
  }
  else {
    speed = -speed;
    analogWrite(MOTOR_PWM_B1_PIN, 0);
    analogWrite(MOTOR_PWM_B2_PIN, (int)((float)speed*2.55));
  }
}

void Motors::setMotorSpeeds(int speed) {
  this->setLeftMotorSpeed(speed);
  this->setRightMotorSpeed(speed);
}

int Motors::getLeftSpeed() {
  return this->leftSpeed;
}

int Motors::getRightSpeed() {
  return this->rightSpeed;
}