#ifndef SHIP_GPS
#define SHIP_GPS

#include "definer.h"
#include "TinyGPS.h"
#include "Ship.h"

class Gps : public Ship {
  private:
    TinyGPS gps;
    float lon, lat;
  public:
    Gps(Stream *serial);
    String serialize();
};

#endif