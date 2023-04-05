#include <HX711.h>

//Load cell input onto HX711 board using a Blend Micro board
//Robert Cundall March 2016
//wire DAT to pin 8, CLK to pin 5, GND to GND and 2.7-5V to VIN

#include "HX711.h"
#define calibration_factor 2000.0
//change this calibration_factor to match the output reading to the applied load 
//if you know the mV/V output from a load cell for the full range output (FRO) use the following formulae to calculate the calibration_factor
//calibration_factor = 4440000 / ((2/mV/V)x FRO)

#define DOUT 5
#define CLK 6
float value;
HX711 scale(DOUT, CLK);

void setup() {
 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  scale.set_scale(calibration_factor); 
  scale.tare();  //Assuming there is no weight on the load cell at start up, this resets the output to 0
  }

void loop() {
  Serial.print("Reading: ");
  value=scale.get_units(), 0;
  
  Serial.print(value); 
  //scale.get_units() returns a float
  Serial.println();
  
  delay(250);// 1/4 second delay

 }
