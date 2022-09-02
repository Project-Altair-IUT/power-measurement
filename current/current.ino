void setup() 
{  
 pinMode(6,INPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 
}
void loop() 
{ 
  /*interrupt pin is not used as the loop is too small and both responses will be close afaik */
  if(digitalRead(6) == 1 )
  { 
    /* when emergency switch is pressed */
    /* 8Green Led turns off >> 7Yellow Led turns on >> 6,4 pin/relay turns on/(motor/power off) >> 1sec delay >> 7yellow turns off >> 5Red turns on */
    
    digitalWrite(8,0);
    digitalWrite(7,1);
    digitalWrite(4,1);
    delay(1000);
    digitalWrite(7,0);
    digitalWrite(5,1);
     
    }
    if(digitalRead(6) == 0 )
  {
    /* when emergency switch is released */
    /* 5Red Led turns off >> 7Yellow Led turns on >> 6,4 pin/relay turns off/(motor/power on) >> 1sec delay >> 7yellow turns off >> 8Green Led turns on */
    digitalWrite(5,0);
    digitalWrite(7,1);
    digitalWrite(4,0);
    delay(1000);
    digitalWrite(7,0);
    digitalWrite(8,1);
    }
}
