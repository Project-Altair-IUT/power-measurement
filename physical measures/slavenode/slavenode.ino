//slave node

#include <Wire.h>

#define slaveAddr 8

#define input A2 

float adc_voltage = 0.0;
float in_voltage = 0.0;
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;  
// Float for Reference Voltage
float ref_voltage = 5.0; 
// Integer for ADC value
int adc_value = 0;


void setup() {
  pinMode(A2, INPUT);
  Wire.begin(slaveAddr);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  
  delay(1);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int i = analogRead(A2);
  Wire.write(i); // respond with message of 6 bytes
  // as expected by master
}