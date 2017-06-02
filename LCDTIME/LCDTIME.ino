#include <RTClib.h>


#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  

//  if (rtc.checkIfAlarm(1)) {
//    Serial.println("Alarm Triggered");
//  }

 //Serial.println();
 //Serial.print("Tempeature = ");
  //lcd.setCursor(13,4);
// lcd.print(rtc.getTemperature()); // คำสั่งดึงอุณหภูมิออกมาแสดง
 // lcd.setCursor(17,4);
 //lcd.print(" C");
 
 lcd.setCursor(0,4);
 lcd.print("Menu");

   Serial.println("By ArduinoALL");
  Serial.println();
  delay(1000);
}
