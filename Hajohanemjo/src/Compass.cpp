#include "shipCompass.h"
#include "shipProject.h"

Compass::Compass() {
  if (__DEBUG) Messenger::Logger("Initialising Compass");
  Wire.begin();
  if (__DEBUG) Messenger::Logger("Waiting: 2000ms");
  delay(2000);

  if (__DEBUG) Messenger::Logger("Initialising MPU");
  this->mpu.setup(0x68);  // change to your own address

  if (__DEBUG) Messenger::Logger("Waiting: 5000ms");
  delay(5000);

  // calibrate anytime you want to
  if (__DEBUG) Messenger::Logger("Calibrating MPU");
  this->mpu.calibrateAccelGyro();
  this->mpu.calibrateMag();
  if (__DEBUG) Messenger::Logger("Calibration DONE");
}

String Compass::serialize() {
  String std = "";
  if (mpu.update()) {
    std = "[\"acc\":{\"x\":\"";
    std += mpu.getAccX();
    std += "\",";
    std += "\"y\":\"";
    std += mpu.getAccY();
    std += "\",";
    std += "\"z\":\"";
    std += mpu.getAccZ();
    std += "\"},";

    std += "\"gyro\":{\"x\":\"";
    std += mpu.getGyroX();
    std += "\",";
    std += "\"y\":\"";
    std += mpu.getGyroY();
    std += "\",";
    std += "\"z\":\"";
    std += mpu.getGyroZ();
    std += "\"},";

    std += "\"deg\":{\"x\":\"";
    std += mpu.getYaw();
    std += "\",";
    std += "\"y\":\"";
    std += mpu.getPitch();
    std += "\",";
    std += "\"z\":\"";
    std += mpu.getRoll();
    std += "\"}]";
  }
  else {
    std = "Waiting for results!";
  }
  return std;
}

void Compass::log() {
  if (mpu.update()) {
    Serial.print(mpu.getAccX()); Serial.print(", ");
    Serial.print(mpu.getAccY()); Serial.print(", ");
    Serial.print(mpu.getAccZ()); Serial.print(", ");

    Serial.print(mpu.getGyroX()); Serial.print(", ");
    Serial.print(mpu.getGyroY()); Serial.print(", ");
    Serial.print(mpu.getGyroZ()); Serial.print(", ");

    Serial.print(mpu.getYaw()); Serial.print(", ");
    Serial.print(mpu.getPitch()); Serial.print(", ");
    Serial.println(mpu.getRoll());
  }
}