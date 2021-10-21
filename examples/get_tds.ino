#include <FB_TDSSensor.h>
#include <FB_AquaTempSensor.h>

#define TDS_PIN A1

FB::AquaTempSensor tempSensor(2);
FB::TDSSensor tdsSensor(A1);

float waterTemp, tdsValue;

void setup() {
  Serial.begin(9600);
  tempSensor.begin();
  tdsSensor.begin();
}

void loop() {
  waterTemp = tempSensor.getWaterTemperature();
  
  Serial.print("Temperature: ");
  Serial.print(waterTemp);
  Serial.println(" °C");

  tdsValue = tdsSensor.getTDS(waterTemp);

  Serial.print("TDS: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");
  
  delay(2000);
}
