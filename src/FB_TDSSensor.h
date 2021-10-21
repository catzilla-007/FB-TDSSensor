#include<EEPROM.h>
#include<GravityTDS.h>

#ifndef FB_TDS_SENSOR_H
#define FB_TDS_SENSOR_H

#define TDS_AREF 5.0
#define TDS_ADC_RANGE 1024

namespace FB {
  class TDSSensor {
    public:
      TDSSensor(int pin);
      void begin();
      float getTDS(float waterTemp);

    private:
      int _pin;
      GravityTDS * _tdsSensor;
  };
}
#endif
