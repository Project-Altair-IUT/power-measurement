#include<SPI.h>
#include<SD.h>
#include <Wire.h>

unsigned long myTime; //variable for storing millis time

File dataFile;
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;  
// Float for Reference Voltage
float ref_voltage = 5.0; 
// Integer for ADC value
int adc_value = 0;

void setup()
{
   // Setup Serial Monitor
   Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
   }
   Serial.print("Initializing SD card...");

   if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
   }
   Serial.println("initialization done.");
   Wire.begin();
   
      Serial.println("DC Voltage and Current Test");
}

uint16_t line = 1;
 
void loop(){

  
  dataFile = SD.open("POWER.txt", FILE_WRITE);
  float v = voltageRead();
  float i = currentRead();
  myTime = millis();
  delay (1000);
  
  if (dataFile) 
  {
    Serial.print(line);    
    Serial.print("  Time = ");
    Serial.println(myTime);
    Serial.print("  ||  Voltage = ");
    Serial.print(v);
    Serial.print("V Current = ");
    Serial.print(i);
    Serial.println("A");
    // Write data to SD card file (POWER.txt)
    dataFile.print(line++);
    dataFile.print("  Time = ");
    dataFile.print(myTime);    
    dataFile.print("  ||  Voltage = ");
    dataFile.print(v);
    dataFile.print("V Current = ");
    dataFile.print(i);
    dataFile.println("A");
    dataFile.close();
  }
  // if the file didn't open, print an error:
  else
    Serial.println("  Error opening POWER.txt");
    delay(1000);
}
