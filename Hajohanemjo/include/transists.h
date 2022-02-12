#ifndef SHIP_TRANSISTS
#define SHIP_TRANSISTS

#include "definer.h"

class Transists {
  private:
    bool blf, blb, brf, brb, ulf, ulb, urf, urb;
    bool line_danger, line_warning;
    bool buffer_warning[30];
    bool buffer_danger[30];
  public:
    Transists();
    bool *getSensorData(); //like: [0] warning, [1] danger
    String serialize();
};

#endif