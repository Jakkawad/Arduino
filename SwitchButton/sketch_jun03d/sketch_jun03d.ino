
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//char weightArray = {"50g", "100g", "150g", "200g", "250g", "300g"};
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
//menu
int lcd_key = 0;
int currentMenu = 1;
int numberClick = 0;
int isSelected = 0;
//selectedOption
int timePerDay = 0;
int weightPerDay = 0;
//define
#define button1  1
#define button2  2
#define button3  3
#define button4  4
#define btnNone 0
 
// read the buttons
int read_LCD_buttons()
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if(buttonState1 == 1) {
//    Serial.println("Button 1");
    return button1;
  } else if(buttonState2 == 1) {
//    Serial.println("Button 2");
    return button2;
  } else if(buttonState3 == 1) {
//    Serial.println("Button 3");
    return button3;
  } else if(buttonState4 == 1) {
//    Serial.println("Button 4");
    return button4;
  } else {
    return btnNone;
  }
}
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  Serial.println("Setup");
}
void loop() {  
 lcd_key = read_LCD_buttons();  // read the buttons
 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case button1:
     {
     Serial.println("button1");
     if(currentMenu == 0) {
      Serial.println("Button = 1, CurrentMenu = 0");
     } else if(currentMenu == 1) {
      Serial.println("Button = 1, CurrentMenu = 1");
      mainMenu();
      currentMenu = 2;
     } else if(currentMenu == 2) {
      Serial.println("Button = 1, CurrentMenu = 2");
      lcd.clear();
      statusMenu();
      currentMenu = 1;
     } else if(currentMenu == 3) {
      Serial.println("Button = 1, CurrentMenu = 3");
     } else if(currentMenu == 4) {
      Serial.println("Button = 1, CurrentMenu = 4");
      mainMenu();
      currentMenu = 2;
      numberClick = 0;
     } else if(currentMenu == 5) {
      Serial.println("Button = 1, CurrentMenu = 5");
     } else if(currentMenu == 6) {
      Serial.println("Button = 1, CurrentMenu = 6");
     } else if(currentMenu == 7) {
      Serial.println("Button = 1, CurrentMenu = 7");
     } else if(currentMenu == 8) {
      mainMenu();
      currentMenu = 2;
      numberClick = 0;
     }
     break;
     }
   case button2:
     {
     Serial.println("Down");
     if(currentMenu == 0) {
      Serial.println("Button = 2, CurrentMenu = 0");
     } else if(currentMenu == 1) {
      Serial.println("Button = 2, CurrentMenu = 1");
      
     } else if(currentMenu == 2) {
      Serial.println("Button = 2, CurrentMenu = 2");
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
     } else if(currentMenu == 3) {
      Serial.println("Button = 2, CurrentMenu = 3");
     } else if(currentMenu == 4) {
      Serial.println("Button = 2, CurrentMenu = 4");
      if(numberClick == 0) {
        numberClick += 1;
        selectItem(19,1);
        unSelectItem(19,3);
      } else if(numberClick == 1) {
        numberClick += 1;
        selectItem(19,2);
        unSelectItem(19,1);
        isSelected = numberClick;
      } else if(numberClick == 2) {
        numberClick += 1;
        selectItem(19,3);
        unSelectItem(19,2);
        isSelected = numberClick;
      } else {
        numberClick = 0;
      }
     } else if(currentMenu == 5) {
      Serial.println("Button = 2, CurrentMenu = 5");
     } else if(currentMenu == 6) {
      Serial.println("Button = 2, CurrentMenu = 6");
     } else if(currentMenu == 7) {
      Serial.println("Button = 2, CurrentMenu = 7");
     } else if(currentMenu == 8) {
      Serial.println("Button = 2, CurrentMenu = 8");
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
     break;
     }
   case button3:
     {
     Serial.println("Select");
     if(currentMenu == 0) {
      mainMenu();
      currentMenu = 1;
      numberClick = 0;
      Serial.println("Button = 3, CurrentMenu = 0");
     } else if(currentMenu == 1) {
      Serial.println("Button = 3, CurrentMenu = 1");
     } else if(currentMenu == 2) {
      Serial.println("Button = 3, CurrentMenu = 2");
      if(isSelected == 1) {
        menuSetDate();
        currentMenu = 3;
        isSelected = 0;
      } else if(isSelected == 2) {
        menuTimePerDay();
        currentMenu = 4;
        isSelected = 0;
      } else if(isSelected == 3) {
        menuWeightPerDay();
        currentMenu = 8;
        isSelected = 0;
      }
     } else if(currentMenu == 3) {
      Serial.println("Button = 3, CurrentMenu = 3");
     } else if(currentMenu == 4) {
      Serial.println("Button = 3, CurrentMenu = 4");
      if(isSelected == 1) {
        Serial.print("=========== 1 Time");
      } else if(isSelected == 2) {
        Serial.print("=========== 2 Time");
      } else if(isSelected == 3) {
        Serial.print("=========== 3 Time");
      }
     } else if(currentMenu == 5) {
      Serial.println("Button = 3, CurrentMenu = 5");
     } else if(currentMenu == 6) {
      Serial.println("Button = 3, CurrentMenu = 6");
     } else if(currentMenu == 7) {
      Serial.println("Button = 3, CurrentMenu = 7");
     } else if(currentMenu == 8) {
      Serial.println("Button = 3, CurrentMenu = 8");
      if(weightPerDay != 0) {
        numberClick = 0;
        mainMenu();
        currentMenu = 2;
      } else {
        Serial.println("WeightPerDay == 0");
      }
     }
     break;
     }
   case button4:
     {
     Serial.println("Back");
     if(currentMenu == 0) {
      mainMenu();
      currentMenu = 1;
      numberClick = 0;
      Serial.println("Button = 4, CurrentMenu = 0");
     } else if(currentMenu == 1) {
      Serial.println("Button = 4, CurrentMenu = 1");
      lcd.clear();
      statusMenu();
      currentMenu = 1;
      numberClick = 0;
     } else if(currentMenu == 2) {
      Serial.println("Button = 4, CurrentMenu = 2");
      statusMenu();
      currentMenu = 1;
     } else if(currentMenu == 3) {
      Serial.println("Button = 4, CurrentMenu = 3");
     } else if(currentMenu == 4) {
      Serial.println("Button = 4, CurrentMenu = 4");
      mainMenu();
      currentMenu = 2;
      numberClick = 0;
     } else if(currentMenu == 5) {
      Serial.println("Button = 4, CurrentMenu = 5");
     } else if(currentMenu == 6) {
      Serial.println("Button = 4, CurrentMenu = 6");
     } else if(currentMenu == 7) {
      Serial.println("Button = 4, CurrentMenu = 7");
     } else if(currentMenu == 8) {
      Serial.println("Button = 4, CurrentMenu = 8");
      mainMenu();
      currentMenu = 2;
      numberClick = 0;
     }
     break;
     }
    case btnNone:
     {
//     Serial.println("Main Menu");
     if(currentMenu == 1) {
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
  lcd.setCursor(13,0);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  
  lcd.setCursor(0,3);
  lcd.print("Menu");
  if(weightPerDay != 0) {
    lcd.setCursor(2,1);
    lcd.print("Weight :");
    lcd.setCursor(11,1);
    lcd.print(weightPerDay);
  }
  if(timePerDay != 0) {
    lcd.setCursor(2,2);
    lcd.print("Time :");
    lcd.print(timePerDay);
  }
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
void menuSetDate() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("set Date");
  DateTime now = rtc.now();
  lcd.setCursor(4,1);
  lcd.print(now.year(), DEC);
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
