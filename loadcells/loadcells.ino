#include "HX711.h"

  HX711 scale;
void setup() {

  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Starting Program");
scale.begin(5,6);
scale.set_scale(8500);
scale.tare();
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Weight: ");
Serial.print(abs(scale.get_units()),1);
Serial.print(" pounds");
Serial.println();
delay(500);
}
