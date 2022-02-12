#include "shipGps.h"

Gps::Gps(Stream *serial) : Ship(serial) {}

String Gps::serialize() {
  while (this->_serial->available()) {
    if(gps.encode(this->_serial->read())) {
      gps.f_get_position(&lat,&lon);
    }
  }
  String std = "{\"lat\":\"";
  std += String(lat,6);
  std += "\",\"lon\":\"";
  std += String(lon,6);
  std += "\",\"course\":\"";
  std += gps.f_course();
  std += "\",\"altitude\":\"";
  std += gps.f_altitude();
  std += "\",\"speed_kmph\":\"";
  std += gps.f_speed_kmph();
  std += "\",\"speed_mps\":\"";
  std += gps.f_speed_mps();
  std += "\",\"speed_knots\":\"";
  std += gps.f_speed_knots();
  std += "\"}";
  return std;
}