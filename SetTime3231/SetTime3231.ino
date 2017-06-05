#include <DS3231.h>
#include <Wire.h>
DS3231 rtc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  rtc.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Time: ");
  Serial.print(rtc.getYear());
  Serial.println("Date: ");
  Serial.print(rtc.getDate());
  delay(1000);
}
