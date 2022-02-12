#include "Ship.h"
#include "messenger.h"
#include "shipProject.h"

Ship::Ship(Stream *serial) {
  this->_serial = serial;
}

Stream *Ship::GetSerial() {
  return this->_serial;
}

void Ship::SerialWrite(const char * msg) {
  this->_serial->println(msg);
}