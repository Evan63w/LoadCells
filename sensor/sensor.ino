#include "HX711.h"

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(5,6);
  scale.set_scale(-7050); 
}

void loop() {
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" lbs"); 
  Serial.println();
  delay(500);
}
