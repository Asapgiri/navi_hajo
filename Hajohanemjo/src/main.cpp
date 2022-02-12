#include "shipProject.h"

Motors *motors;
ServoControll *servo;
Compass *compass;
Gps *gps;
Transists *transists;
Wifi *wifi;

void setup() {
  Serial.begin(250000);
  Serial1.begin(9600); // NodeMCU
  Serial2.begin(9600); // GPS
  while (!Serial && !Serial1 && !Serial2);

  //servo = new ServoControll(&Serial, STEARING_SERVO_PIN, STEARING_SERVO_OFFSET, STEARING_SERVO_REVERSE);
  gps = new Gps(&Serial2);
  compass = new Compass();
  motors = new Motors();

  //wifi = new Wifi(&Serial, motors, servo, compass, gps, transists);
  wifi = new Wifi(&Serial1, motors, servo, compass, gps, transists);
  delay(3000);
  //servo->RotateToDegree(0);
}

unsigned long time_1 = 0;
unsigned long time_3 = 0;
bool right = true;

void loop() {
  if (millis() > time_1) {
    Serial.println("Im awake!");
    //Serial.println(gps->serialize());
    time_1 = millis() + 1000;
  }
  wifi->HandleRequest();
}