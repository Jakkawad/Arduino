#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);

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
int isSelected = 0;
int numberClick = 0;
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
//  lcd.begin(20, 4);
  lcd.backlight();
  lcd.setCursor(2,2);
//  lcd.print("Loading...");
//  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  lcd.clear();
//  if(currentMenu == 0) {
//    lcd.clear();
//    clearAllLCD();
//    lcd.setCursor(0,0);
//    lcd.print("DD/MM/YYYY");
//    lcd.setCursor(15,0);
//    lcd.print("12:12");
//    lcd.setCursor(0,3);
//    lcd.print("Menu");
//  }
//  delay(1000);
//  Serial.println("void loop");
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if(buttonState1 == LOW && prevButtonState1 == HIGH) {
    Serial.println("Button 1");
    //enter menu
    if(currentMenu == 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set Date");
      lcd.setCursor(0,1);
      lcd.print("Time Per Day");
      prevButtonState1 = buttonState1;
      currentMenu = 1;
    } else if(currentMenu == 3) {
      
      Serial.print("Exit To Main Menu");
    }
    prevButtonState1 = buttonState1;
  } else if(buttonState2 == LOW && prevButtonState2 == HIGH) {
    Serial.println("Button 2");
    //enter menu
    if(currentMenu == 1) {
      setDate();
    } else if(currentMenu == 3) {
      Serial.println("=========");
      if(numberClick == 0) { //<=
        numberClick = 3;
        selectItem(17,1);
        unSelectItem(17,1);
        timePerDay = 1;
        Serial.println("UP0");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick == 1) {
        numberClick = 0;
        selectItem(17,1);
        unSelectItem(17,2);
        Serial.println("UP1");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick == 2) {
        numberClick = 1;
        selectItem(17,2);
        unSelectItem(17,3);
        Serial.println("UP2");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick = 3) {
        numberClick = 2;
        selectItem(17,3);
        unSelectItem(17,1);
        Serial.println("UP3");
        Serial.println(numberClick);
        Serial.println("=========");
      } else {
        Serial.println("Remove All");
      }
    }
    prevButtonState2 = buttonState2;
  } else if(buttonState3 == LOW && prevButtonState3 == HIGH) {
    Serial.println("Button 3");
    //enter menu
    if(currentMenu == 1) {
      setTimePerDay();
    } else if(currentMenu == 3) {
      Serial.println("=========");
      if(numberClick == 0) { //<=
        numberClick = 1;
        selectItem(17,1);
        unSelectItem(17,3);
        timePerDay = 1;
        Serial.println("Down0");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick == 1) {
        numberClick = 2;
        selectItem(17,2);
        unSelectItem(17,1);
        Serial.println("Down1");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick == 2) {
        numberClick = 3;
        selectItem(17,3);
        unSelectItem(17,2);
        Serial.println("Down2");
        Serial.println(numberClick);
        Serial.println("=========");
      } else if(numberClick = 3) {
        numberClick = 0;
        selectItem(17,3);
        unSelectItem(17,3);
        Serial.println("Down3");
        Serial.println(numberClick);
        Serial.println("=========");
      } else {
        Serial.println("Remove All");
      }
    }
    prevButtonState3 = buttonState3;
  } else if(buttonState4 == LOW && prevButtonState4 == HIGH) {
    Serial.println("Button 4");
    //enter menu
    if(currentMenu == 1) {
      Serial.println("OK");
      if(isSelected == 1) {
        Serial.println("Date");
      } else if(isSelected == 2) {
        Serial.println("Time");
        setTimePerDayMenu();
        setTime1();
        currentMenu = 3;
      } else {
        Serial.println("Error");
      }
    } else if(currentMenu == 3) {
      Serial.println("OK");
      Serial.println(timePerDay);
    }
    prevButtonState4 = buttonState4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;
  }
}
void intoMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Date");
  lcd.setCursor(0,1);
  lcd.print("Time Per Day");
  lcd.setCursor(0,2);
  lcd.print("Weight Per Time");
}
void setDate() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Date <==");
  lcd.setCursor(0,1);
  lcd.print("Time Per Day");
  isSelected = 1;
  Serial.println(isSelected);
}
void setTimePerDay() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set Date");
  lcd.setCursor(0,1);
  lcd.print("Time Per Day <==");
  isSelected = 2;
  Serial.println(isSelected);
}
void mainMenu() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("");
  lcd.setCursor(0,1);
  lcd.print("");
  lcd.setCursor(0,2);
  lcd.print("");
}
void setTimePerDayMenu() {
  lcd.clear();
  lcd.setCursor(12,0);
  lcd.print("12:12");
}
void setTime1() {
  lcd.setCursor(0,1);
  lcd.print("1. 1 Time Per Day");
  lcd.setCursor(0,2);
  lcd.print("2. 2 Time Per Day");
  lcd.setCursor(0,3);
  lcd.print("3. 3 Time Per Day");
}

void selectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("<==");
}
void unSelectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("   ");
}
void clearLCD() {
  lcd.setCursor(0,0);
  lcd.print("          ");
  lcd.setCursor(15,0);
  lcd.print("     ");
  lcd.setCursor(0,3);
  lcd.print("    ");
}
void clearAllLCD() {
  lcd.setCursor(0,0);
  lcd.print("                    ");
  lcd.setCursor(0,1);
  lcd.print("                    ");
  lcd.setCursor(0,2);
  lcd.print("                    ");
  lcd.setCursor(0,3);
  lcd.print("                    ");
}

