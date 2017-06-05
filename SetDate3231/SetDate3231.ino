
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int prevButtonState1;
int prevButtonState2;
int prevButtonState3;
int prevButtonState4;
//menu
int lcd_key = 0;
int currentMenu = 1;
int numberClick = 0;
int isSelected = 0;
//selectedOption
int timePerDay = 0;
int weightPerDay = 0;
//define button
#define button1  1
#define button2  2
#define button3  3
#define button4  4
#define btnNone 0
//define 
int timeInDay1 = 0;
int hours1 = 0;
int minutes1 = 0;
int nowHours = 0;
int nowMinutes = 0;
// 0:00 - 23:59 time in day
// hours = 23
// minutes = 59
// 1 time - 3 time per day

// read the buttons
int read_LCD_buttons()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if(buttonState1 == LOW && prevButtonState1 == HIGH) {
    prevButtonState1 = buttonState1;
    return button1;
  } else if(buttonState2 == LOW && prevButtonState2 == HIGH) {
    prevButtonState2 = buttonState2;
    return button2;
  } else if(buttonState3 == LOW && prevButtonState3 == HIGH) {
    prevButtonState3 = buttonState3;
    return button3;
  } else if(buttonState4 == LOW && prevButtonState4 == HIGH) {
    prevButtonState4 = buttonState4;
    return button4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;
    return btnNone;
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  Serial.println("Setup");

}

void loop() {
  // put your main code here, to run repeatedly:
//  checkTime();
  DateTime now = rtc.now();
//  Serial.print(now.year(), DEC);
//  Serial.print('/');
//  Serial.print(now.month(), DEC);
//  Serial.print('/');
//  Serial.print(now.day(), DEC);
//  Serial.print("<=====>");
//  Serial.print(now.hour(), DEC);
//  Serial.print(':');
//  Serial.print(now.minute(), DEC);
//  Serial.print(':');
//  Serial.print(now.second(), DEC);
//  Serial.println();
  nowHours = (now.hour());
  Serial.println("nowHours");
  Serial.print(nowHours);
  lcd_key = read_LCD_buttons();
  switch (lcd_key) {
    case button1: {
      Serial.println("Case 1");
      Serial.println(now.minute(), DEC);
      setTime();
      break;
    }
    case button2: {
      Serial.println("Case 2");
      if(hours1 >= 23) {
        hours1 = 0;
      } else {
        hours1 += 1;
      }
      setTime();
      break; 
    }
    case button3: {
      Serial.println(hours1);
      Serial.println("Case 3");
//      hours1 -= 1;
      if(hours1 <= 0) {
        hours1 = 23;
      } else {
        hours1 -= 1;
      }
      setTime();
      break;
    }
    case button4: {
      Serial.println("Case 4");
      break;
    }
    case btnNone: {
//      Serial.println("Case None");
      statusMenu();
      break;
    }
  }

}
void statusMenu() {
  DateTime now = rtc.now();
  lcd.setCursor(0,0);
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  lcd.setCursor(12,0);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
//  minutes1 = (now.minute(), DEC);
//  Serial.println("Minutes ==");
//  Serial.print(minutes1);
}
void setTime() {
  lcd.setCursor(0,1);
//  lcd.print("00:00");
  lcd.print(hours1);
  lcd.print(":");
  lcd.print(minutes1);
}
void checkTime() {
  DateTime now = rtc.now();
//  int nowHour = (now.hour(), DEC);
//  Serial.println("nowHour ===");
//  Serial.print(nowHour);
//  if(hours1 == nowHour) {
//    Serial.println("Check True");
//  } else {
//    
//  }
}

