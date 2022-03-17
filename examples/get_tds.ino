#include <FB_TDSSensor.h>
#include <FB_AquaTempSensor.h>

#define TDS_PIN A1
#define TEMP_PIN 2

FB::AquaTempSensor tempSensor(TEMP_PIN);
FB::TDSSensor tdsSensor(TDS_PIN);

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
