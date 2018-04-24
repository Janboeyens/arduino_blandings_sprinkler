/*
RST -> Pin 2  digital
DATA pin 3  digital
CLK pin 4 digital

*/
#include <DS1302.h>
#include <Wire.h>  
DS1302 rtc(2, 3, 4);



void setup()
{

   Serial.begin(9600);
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  
  // The following lines sets the time to the DS 1302
rtc.setDOW(SUNDAY);        // Set Day-of-Week to FRIDAY
rtc.setTime(20, 32, 0);     // Set the time to 12:00:00 (24hr format)
rtc.setDate(15, 4, 2018);   // Set the date to August 6th, 2010
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(rtc.getTimeStr());
  
Serial.println(rtc.getDOWStr(FORMAT_SHORT));
Serial.println(rtc.getDOWStr(FORMAT_LONG));
  
  // Display date in the lower right corner
Serial.println(rtc.getDateStr());
delay(5000);
}
