#ifndef SHIP_TEMPS
#define SHIP_TEMPS

class Temps {
  private:
    float air_temp;
    float battery_temp;
    float water_temp;
  public:
    Temps();
    Temps(float _air_temp, float _battery_temp, float _water_temp);
    void setTemps(float _air_temp, float _battery_temp, float _water_temp);
    void setAir(float temp);
    void setBattery(float temp);
    void setWater(float temp);
    float getAir();
    float getBattery();
    float getWater();
    String serialize();
};

#endif