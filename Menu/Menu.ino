#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27,20,4);

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

const int ledPin = 13;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

//menu
int currentMenu = 0;
int subMenu = 0;
int isSelected = 0;
int numberClick = 0;
int settingMenu = 0;

//selectedOption
int timePerDay = 0;
int weightPerDay = 0;

int prevButtonState1;
int prevButtonState2;
int prevButtonState3;
int prevButtonState4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin2, LOW);
  digitalWrite(buttonPin3, LOW);
  digitalWrite(buttonPin4, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
//  lcd.print("Loading....");

  rtc.begin();
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//    rtc.adjust(DateTime(__DATE__, __TIME__));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  // put your main code here, to run repeatedly:

//  statusMenu();
  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  if(buttonState1 == LOW && prevButtonState1 == HIGH) {
    Serial.println("Button 1");
    if(currentMenu == 0) {
      intoMenu();
      currentMenu = 1;
    } else if(currentMenu == 1) {
      Serial.println("Exit to MainMenu 1");
    } else if(currentMenu == 2) {
      Serial.println("Exit to MainMenu 2");
    } else if(currentMenu == 3) {
      Serial.println("Exit to MainMenu 3");
    }
    prevButtonState1 = buttonState1;
  } else if(buttonState2 == LOW && prevButtonState2 == HIGH) {
    Serial.println("Button 2");
    if(currentMenu == 1) {
      if(numberClick == 0) {
        numberClick += 1;
        selectItem(19,1);
        unSelectItem(19,3);
        Serial.println(numberClick);
        isSelected = numberClick;
      } else if(numberClick == 1) {
        numberClick += 1;
        selectItem(19,2);
        unSelectItem(19,1);
        Serial.println(numberClick);
        isSelected = numberClick;
      } else if(numberClick == 2) {
        numberClick += 1;
        selectItem(19,3);
        unSelectItem(19,2);
        Serial.println(numberClick);
        isSelected = numberClick;
      } else {
        numberClick = 0;
      }
    } else if(currentMenu == 2) {
      Serial.println("currentMenu = 2");
      Serial.println(numberClick);
      if(numberClick == 0) {
        numberClick += 1;
        selectItem(19,1);
        unSelectItem(19,3);
        timePerDay = 1;
      } else if(numberClick == 1) {
        numberClick += 1;
        selectItem(19,2);
        unSelectItem(19,1);
        timePerDay = 2;
      } else if(numberClick == 2) {
        numberClick += 1;
        selectItem(19,3);
        unSelectItem(19,2);
        timePerDay = 3;
      } else {
        numberClick = 0;
      }
    } else if(currentMenu == 3) {
      weightPerDay = 0;
      Serial.println("currentMenu = 3");
      if(numberClick == 0) {
        numberClick += 1;
        selectItem(8,1);
        unSelectItem(19,3);
        weightPerDay = 1;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else if(numberClick == 1) {
        numberClick += 1;
        selectItem(8,2);
        unSelectItem(8,1);
        weightPerDay = 2;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else if(numberClick == 2) {
        numberClick += 1;
        selectItem(8,3);
        unSelectItem(8,2);
        weightPerDay = 3;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else if(numberClick == 3) {
        numberClick += 1;
        selectItem(19,1);
        unSelectItem(8,3);
        weightPerDay = 4;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else if(numberClick == 4) {
        numberClick += 1;
        selectItem(19,2);
        unSelectItem(19,1);
        weightPerDay = 5;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else if(numberClick == 5) {
        numberClick += 1;
        selectItem(19,3);
        unSelectItem(19,2);
        weightPerDay = 6;
        Serial.println("WeightPerDay");
        Serial.println(weightPerDay);
        Serial.println("========");
      } else {
        numberClick = 0;
      }
    }
    prevButtonState2 = buttonState2;
  } else if(buttonState3 == LOW && prevButtonState3 == HIGH) {
    Serial.println("Button 3");
    Serial.println(currentMenu);
    Serial.println("=========");
    if(currentMenu == 1) {
      Serial.println("OK");
      if(isSelected == 1) {
        Serial.println("isSelected 1");
        Serial.println(numberClick);
        menuSetDate();
//        currentMenu = isSelected;
      } else if(isSelected == 2) {
        Serial.println("isSelected 2");
        Serial.println(numberClick);
        numberClick = 0;
        menuTimePerDay();
        currentMenu = isSelected;
      } else if(isSelected == 3) {
        Serial.println("isSelected 3");
        Serial.println(numberClick);
        numberClick = 0;
        menuWeightPerDay();
        currentMenu = isSelected;
      }
    } else if(currentMenu == 2) {
      Serial.println("CurrentMenu 2 Button 3");
      if(timePerDay != 0) {
        Serial.println("Time Per Day");
        Serial.println(timePerDay);
        currentMenu = 5;
//        intoMenu();
        if(timePerDay == 1) {
          setDatePerTime1();
        }
      }
    } else if(currentMenu == 3) {
      if(weightPerDay != 0) {
        Serial.println("CurrentMenu 3 Button 3");
        Serial.println("Weight Per Day");
        Serial.println(weightPerDay);
//        settingMenu = 1;
        currentMenu = 1;
        intoMenu();
      }
    } else if(currentMenu == 4) {
      Serial.println("CurrentMenu 4 Button 3");
    } else {
      Serial.println("Error");
    }
    prevButtonState3 = buttonState3;
  } else if(buttonState4 == LOW && prevButtonState4 == HIGH) {
    Serial.println("Button 4");
    if(currentMenu == 1) {
      Serial.println("Cancle");
      numberClick = 0;
      intoMenu();
      currentMenu = 1;
      settingMenu = 1;
    } else if(currentMenu == 2) {
      Serial.println("CurrentMenu 2 Button 4");
      intoMenu();
      currentMenu = 1;
    } else if(currentMenu == 3) {
      Serial.println("CurrentMenu 3 Button 4");
      intoMenu();
      currentMenu = 1;
    } else if(currentMenu == 4) {
      Serial.println("CurrentMenu 4 Button 4");
    }
    prevButtonState4 = buttonState4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;

//    if(settingMenu == 1) {
//      lcd.clear();
//      statusMenu();
//      delay(1000);
//    }
//    Serial.println("Status Menu"); 
//    statusMenu();
//    delay(300);
  }
}
void clearRowLCD(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("                    ");
  Serial.println("ClearRowLCD");
}
void statusMenu() {
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DD/MM/YYYY");
  lcd.setCursor(15,0);
  lcd.print("12:12");
  lcd.setCursor(0,3);
  lcd.print("Menu");
//  lcd.clear();
  //
  if(weightPerDay != 0) {
    lcd.setCursor(0,1);
    lcd.print("Weight =");
  }
  if(timePerDay != 0) {
    lcd.setCursor(0,2);
    lcd.print("Time Per Day");
  }
  
//  delay(50);
}
void intoMenu() {
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
void menuSetDate() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("set Date");
  DateTime now = rtc.now();
  lcd.setCursor(4,1);
  lcd.print(now.year(), DEC);
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
}
void setDatePerTime1() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Date");
  lcd.setCursor(0,1);
  lcd.print("Date 1 =");
}
void setDatePerTime2() {
  
}
void setDatePerTime3() {
  
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
void selectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("<");
}

void unSelectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print(" ");
}
