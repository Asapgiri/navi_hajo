#ifndef SHIP_MESSENGER
#define SHIP_MESSENGER

#include <Arduino.h>

class Messenger {
  public:
    static void Logger(String msg);
    static void Logger(String msg[]);
};

#endif