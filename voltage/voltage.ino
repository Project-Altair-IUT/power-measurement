float voltageRead(){
  // Read the Analog Input
   adc_value = analogRead(A0);   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0;    
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ;   
   // Print results to Serial Monitor to 2 decimal places
  return(in_voltage);
}
