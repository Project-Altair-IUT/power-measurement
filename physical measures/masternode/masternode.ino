//master node

#include <Wire.h>
#include<SD.h>
int i;
int arrayVoltage[10];
int arrayCurrent[14];

File dataFile;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
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

   Serial.println("Slave to master data:");
   }


uint16_t line = 1;
void loop() {

  dataFile = SD.open("POWER.txt", FILE_WRITE);
  Wire.requestFrom(8, 1);    // request 6 bytes from peripheral device #8

  while (Wire.available()) { // peripheral may send less than requested
    i = Wire.read(); // receive a byte as character
    // Serial.println(i);         // print the character
  }
  if (dataFile) 
  {
    Serial.print(line);    
    Serial.print(" Data :");
    Serial.println(i);
  
    // Write data to SD card file (POWER.txt)
    dataFile.print(line++);
    dataFile.print(" Data : ");
    dataFile.print(i);    
    
    dataFile.close();
  }
  // if the file didn't open, print an error:
  else
    Serial.println("  Error opening POWER.txt");
    delay(1000);  
  
  delay(1);
}


