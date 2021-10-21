#include <FB_TDSSensor.h>

namespace FB {
  TDSSensor::TDSSensor(int pin) {
    _pin = pin;
    _tdsSensor = new GravityTDS();
  }

  void TDSSensor::begin() {
    _tdsSensor->setPin(_pin);
    _tdsSensor->setAref(TDS_AREF);
    _tdsSensor->setAdcRange(TDS_ADC_RANGE);
    _tdsSensor->begin();
  }

  float TDSSensor::getTDS(float waterTemp) {
    _tdsSensor->setTemperature(waterTemp);
    _tdsSensor->update();
    return _tdsSensor->getTdsValue();
  }
}