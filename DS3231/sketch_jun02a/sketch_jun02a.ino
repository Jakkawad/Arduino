#include "rtclib.h"

rtc_DS3231 rtc;
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);
void setup()
{
//lcd.begin (16,2); // <
  lcd.begin (20,4); // <

// Switch on the backlight
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(__DATE__, __TIME__));

  if (! rtc.isrunning()) {
    Serial.println("rtc is NOT running!");
    // following line sets the rtc to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  DateTime now = rtc.now();
  /* ตั้งเวลา ในตัวอย่างนี้ เซตค่าเป็นเวลา 23:09 ถ้าถึงเวลานี้จะให้ทำงานที่ฟังก์ชัน 
    rtc.setAlarm1Simple(23, 9);
   if (rtc.checkIfAlarm(1)) {
   Serial.println("Alarm Triggered");
   }*/
  rtc.setAlarm1Simple(23, 9);

  rtc.turnOnAlarm(1);

  if (rtc.checkAlarmEnabled(1)) {
    Serial.println("Alarm Enabled");
  }

}



void loop()
{
DateTime now = rtc.now();
  
  Serial.print(now.year(), DEC);//ดึงปีออกมาแสดง
  lcd.setCursor(6,0);
   lcd.print(now.year(), DEC);
  Serial.print('/');
  lcd.setCursor(7,0);
  
 Serial.print(now.month(), DEC);
   lcd.setCursor(4,0);
    lcd.print(now.month(), DEC);//ดึงเดือนออกมาแสดง
  lcd.setCursor(5,0);
  Serial.print('/');
 lcd.print('/');
  
  Serial.print(now.day(), DEC);
  lcd.setCursor(1,0);
  lcd.print(now.day(), DEC);//ดึงวันที่ออกมาแสดง
   Serial.print('/');
  lcd.setCursor(3,0);
  lcd.print('/');

  
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  lcd.setCursor(11,0);
  lcd.print(now.hour(), DEC);//ดึงชั่วโมงออกมาแสดง
  
  Serial.print(':');
   lcd.setCursor(13,0);
   lcd.print(':');
   
  Serial.print(now.minute(), DEC);
  lcd.setCursor(14,0);
 lcd.print(now.minute(), DEC);//ดึงนาทีออกมาแสดง
  
  Serial.print(':');
  lcd.setCursor(16,0);
   lcd.print(':');
  
  Serial.print(now.second(), DEC);
  lcd.setCursor(17,0);
  lcd.print(now.second(), DEC);//ดึงวินาทีออกมาแสดง
  

  if (rtc.checkIfAlarm(1)) {
    Serial.println("Alarm Triggered");
  }

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
  //if(now.hour ==23 && now.minute == 59 ){

    //Serial.println("ok");
  //}
