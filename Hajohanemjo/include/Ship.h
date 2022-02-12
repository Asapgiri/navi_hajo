#ifndef SHIP_BASE
#define SHIP_BASE

#include <Stream.h>

class Ship {
  protected:
    Stream *_serial;
  public:
    Ship(Stream *serial);
    void SerialWrite(const char *msg);
    Stream *GetSerial();
};

#endif