#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is connected to pin 2 on Arduino
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int bodyCount = 0;
float threshold = 30.0;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  Serial.println("DS18B20 Sensor Initialized");
}

void loop() {
  sensors.requestTemperatures(); 
  float temperature = sensors.getTempCByIndex(0);//for getting temperature in celcius 

  if (temperature > threshold) {
    bodyCount++;
    Serial.print("Heated body detected! Total bodies: ");
    Serial.println(bodyCount);
  } else {
    Serial.println("No heated body detected. Temperature: " + String(temperature));
  }

  delay(1000);
}
