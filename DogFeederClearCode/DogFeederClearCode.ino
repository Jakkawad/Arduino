
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;
//define
#define button1  1
#define button2  2
#define button3  3
#define button4  4
#define buttonNone 0
//button 
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
int buttonKey = 0;
int currentMenu = 1;
int numberClick = 0;
int isSelected = 0;
int applySetTime = 0;
// value status
int weightPerDay = 0;
int timePerDay = 0;
int timerSelected = 0;
//time value
int hours1 = 0;
int minutes1 = 0;
int hours2 = 0;
int minutes2 = 0;
int hours3 = 0;
int minutes3 = 0;
//time now
int nowDay = 0;
int nowMonth = 0;
int nowYear = 0;
int nowHour = 0;
int nowMinute = 0;
int nowSecond = 0;

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  if(! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if(rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonKey = read_LCD_Button();
  switch (buttonKey) {
    case button1: {
      Serial.println("Button 1");
      if(currentMenu == 1) {
        Serial.println("Button 1 Menu 1");
//        mainMenu();
//        currentMenu = 2;
      } else if(currentMenu == 2) {
        Serial.println("Button 1 Menu 2");
      } else if(currentMenu == 3) {
        Serial.println("Button 1 Menu 3");
      } else if(currentMenu == 4) {
        Serial.println("Button 1 Menu 4");
      } else if(currentMenu == 5) {
        Serial.println("Button 1 Menu 5");
      } else if(currentMenu == 6) {
        Serial.println("Button 1 Menu 6");
      }
      break;
    }
    case button2: {
      Serial.println("Button 2");
      if(currentMenu == 1) {
        Serial.println("Button 2 Menu 1");
      } else if(currentMenu == 2) {
        Serial.println("Button 2 Menu 2");
//        if(numberClick == 0) {
//        numberClick += 1;
//        selectItem(19,1);
//        unSelectItem(19,3);
//        Serial.println(numberClick);
//        isSelected = numberClick;
//      } else if(numberClick == 1) {
//        numberClick += 1;
//        selectItem(19,2);
//        unSelectItem(19,1);
//        Serial.println(numberClick);
//        isSelected = numberClick;
//      } else if(numberClick == 2) {
//        numberClick += 1;
//        selectItem(19,3);
//        unSelectItem(19,2);
//        Serial.println(numberClick);
//        isSelected = numberClick;
//      } else {
//        numberClick = 0; 
//      }
      } else if(currentMenu == 3) {
        Serial.println("Button 2 Menu 3");
      } else if(currentMenu == 4) {
        Serial.println("Button 2 Menu 4");
      } else if(currentMenu == 5) {
        Serial.println("Button 2 Menu 5");
      } else if(currentMenu == 6) {
        Serial.println("Button 2 Menu 6");
//        if(numberClick == 0) {
//        numberClick += 1;
//        selectItem(8,1);
//        unSelectItem(19,3);
//        weightPerDay = 1;
//      } else if(numberClick == 1) {
//        numberClick += 1;
//        selectItem(8,2);
//        unSelectItem(8,1);
//        weightPerDay = 2;
//      } else if(numberClick == 2) {
//        numberClick += 1;
//        selectItem(8,3);
//        unSelectItem(8,2);
//        weightPerDay = 3;
//      } else if(numberClick == 3) {
//        numberClick += 1;
//        selectItem(19,1);
//        unSelectItem(8,3);
//        weightPerDay = 4;
//      } else if(numberClick == 4) {
//        numberClick += 1;
//        selectItem(19,2);
//        unSelectItem(19,1);
//        weightPerDay = 5;
//      } else if(numberClick == 5) {
//        numberClick += 1;
//        selectItem(19,3);
//        unSelectItem(19,2);
//        weightPerDay = 6;
//      } else {
//        numberClick = 0;
//      }
      break;
    }
    case button3: {
      Serial.println("Button 3");
      if(currentMenu == 1) {
        Serial.println("Button 3 Menu 1");
      } else if(currentMenu == 2) {
        Serial.println("Button 3 Menu 2");
//        if(isSelected == 1) {
//        lcd.clear();
//        menuSetDate();
//        currentMenu = 3;
//        isSelected = 0;
//        numberClick = 0;
//      } else if(isSelected == 2) {
//        menuTimePerDay();
//        currentMenu = 4;
//        isSelected = 0;
//        numberClick = 0;
//      } else if(isSelected == 3) {
//        menuWeightPerDay();
//        currentMenu = 6;
//        isSelected = 0;
//        numberClick = 0;
//      }
      } else if(currentMenu == 3) {
        Serial.println("Button 3 Menu 3");
      } else if(currentMenu == 4) {
        Serial.println("Button 3 Menu 4");
//        if(isSelected == 1) {
////        Serial.print("=========== 1 Time");
//        currentMenu = 5;
//        menuSetTimeX(1);
//        numberClick = 0;
//        timerSelected = 1;
//      } else if(isSelected == 2) {
////        Serial.print("=========== 2 Time");
//        currentMenu = 5;
//        menuSetTimeX(2);
//        numberClick = 0;
//        timerSelected = 2;
//      } else if(isSelected == 3) {
////        Serial.print("=========== 3 Time");
//        currentMenu = 5;
//        menuSetTimeX(3);
//        numberClick = 0;
//        timerSelected = 3;
//      }
      } else if(currentMenu == 5) {
        Serial.println("Button 3 Menu 5");
      } else if(currentMenu == 6) {
        Serial.println("Button 3 Menu 6");
//        if(weightPerDay != 0) {
//          numberClick = 0;
//          mainMenu();
//          currentMenu = 2;
//      }
      break;
    }
    case button4: {
      Serial.println("Button 4");
//      if(currentMenu == 1) {
//        Serial.println("Button 4 Menu 1");
//      } else if(currentMenu == 2) {
//        Serial.println("Button 4 Menu 2");
//        lcd.clear();
//        statusMenu();
//        currentMenu = 1;
//      } else if(currentMenu == 3) {
//        Serial.println("Button 4 Menu 3");
//      } else if(currentMenu == 4) {
//        Serial.println("Button 4 Menu 4");
//        mainMenu();
//        currentMenu = 2;
//        numberClick = 0;
//      } else if(currentMenu == 5) {
//        Serial.println("Button 4 Menu 5");
//      } else if(currentMenu == 6) {
//        Serial.println("Button 4 Menu 6");
//        lcd.clear();
//        mainMenu();
//        currentMenu = 2;
//        numberClick = 0;
//      }     
      break;
    }
    case buttonNone: {
//      Serial.println("ButtonNone");
      if(currentMenu ==  1) {
        statusMenu();
      }
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
  numberOfTime(now.hour(), 1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  numberOfTime(now.minute(), 1);
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  numberOfTime(now.second(), 1);
  lcd.setCursor(0,3);
  lcd.print("Menu");
  //weight
  lcd.setCursor(0,3);
  lcd.print("Menu");
}
void mainMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("==== MAIN MENU ====");
  lcd.setCursor(0,1);
  lcd.print("1. Set Date");
  lcd.setCursor(0,2);
  lcd.print("2. Time Per Day");
  lcd.setCursor(0,3);
  lcd.print("3. Weight Per Time");
}
void menuTimePerDay() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Time Per Day");
  lcd.setCursor(0,1);
  lcd.print("1. 1 Time Per Day");
  lcd.setCursor(0,2);
  lcd.print("2. 2 Time Per Day");
  lcd.setCursor(0,3);
  lcd.print("3. 3 Time Per Day");
  applySetTime = 0;
}
void menuSetDate() {
  lcd.setCursor(0,0);
  lcd.print("Set Date");
  DateTime now = rtc.now();
  nowDay = now.day();
  nowMonth = now.month();
  nowYear = now.year();
  nowHour = now.hour();
  nowMinute = now.minute();
  nowSecond = now.second();
  lcd.setCursor(0,1);
  lcd.print(nowDay);
  lcd.print("/");
  lcd.print(nowMonth);
  lcd.print("/");
  lcd.print(nowYear);
  lcd.setCursor(0,2);
  numberOfTime(nowHour, 1);
  lcd.print(nowHour);
  lcd.print(":");
  numberOfTime(nowMinute, 1);
  lcd.print(nowMinute);
  lcd.print(":");
  lcd.print(nowSecond);
//  if(nowSecond <= 9) {
//    numberOfTime(nowSecond,2);
//  } else {
//    numberOfTime(nowSecond,1);
//  }
  numberOfTime(nowSecond, 2);
}
void menuSetTimeX(int n) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Time ");
  lcd.print(n);
  timePerDay = n;
  Serial.println("TimePerDay = ");
  Serial.print(timePerDay);
  if(n == 1) {
    menuSetTime1();
  } else if(n == 2) {
    menuSetTime1();
    menuSetTime2();
  } else if(n == 3) {
    menuSetTime1();
    menuSetTime2();
    menuSetTime3();
  }
}
void menuSetTime1() {
  lcd.setCursor(1,1);
  lcd.print("Time=>1 = ");
  if(hours1 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours1);
  lcd.print(":");
  if(minutes1 <= 9) {
    lcd.print("0");
    lcd.print(minutes1);
  } else {
    lcd.print(minutes1);
  }
}
void menuSetTime2() {
  lcd.setCursor(1,2);
  lcd.print("Time=>2 = ");
  if(hours2 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours2);
  lcd.print(":");
  if(minutes2 <= 9) {
    lcd.print("0");
    lcd.print(minutes2);
  } else {
    lcd.print(minutes2);
  }
}
void menuSetTime3() {
  lcd.setCursor(1,3);
  lcd.print("Time=>3 = ");
  if(hours3 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours3);
  lcd.print(":");
  if(minutes3 <= 9) {
    lcd.print("0");
    lcd.print(minutes3);
  } else {
    lcd.print(minutes3);
  }
}
void applyTime() {
  lcd.setCursor(15,0);
  lcd.print("=> OK");
}
void setHourMinute(int t, int hm) {
  if(t == 1) {
    lcd.setCursor(18,3);
    lcd.print(" ");
    lcd.setCursor(18,1);
    if(hm == 1) {
      lcd.print("H");
    } else if(hm == 2) {
      lcd.print("M");
    }
  } else if(t == 2) {
    lcd.setCursor(18,1);
    lcd.print(" ");
    lcd.setCursor(18,2);
    if(hm == 1) {
      lcd.print("H");
    } else if(hm == 2) {
      lcd.print("M");
    }
  } else if(t == 3) {
    lcd.setCursor(18,2);
    lcd.print(" ");
    lcd.setCursor(18,3);
    if(hm == 1) {
      lcd.print("H");
    } else if(hm == 2) {
      lcd.print("M");
    }
  }
}
void menuWeightPerDay() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Weight Per Day");
  lcd.setCursor(0,1);
  lcd.print("1. 50g");
  lcd.setCursor(0,2);
  lcd.print("2. 100g");
  lcd.setCursor(0,3);
  lcd.print("3. 150g");
  lcd.setCursor(10,1);
  lcd.print("4. 200g");
  lcd.setCursor(10,2);
  lcd.print("5. 250g");
  lcd.setCursor(10,3);
  lcd.print("6. 300g");
}
void numberOfTime(int t, int o) {
   if(o == 1) {
    if(t <= 9) {
      lcd.print("0");
    }
   } else if(o == 2) {
    if(t <= 9) {
      lcd.print(" ");
    }
   }
}
//select
void selectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("<");
}
void unSelectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print(" ");
}
//read button
int read_LCD_Button() {
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
    return buttonNone;
  }
}
