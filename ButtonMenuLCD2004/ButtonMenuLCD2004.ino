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

int currentMenu = 0;
int isSelected = 0;
int numberClick = 0;

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
  lcd.setCursor(0,0);
  lcd.print("Hello");
//  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
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
    }
    prevButtonState1 = buttonState1;
  } else if(buttonState2 == LOW && prevButtonState2 == HIGH) {
    Serial.println("Button 2");
    if(currentMenu == 1) {
      setDate();
    } else if(currentMenu == 3) {
      if(numberClick == 0) {
        numberClick = 1;
        selectItem(17,1);
      } else if(numberClick == 1) {
        numberClick = 2;
        selectItem(17,2);
        unSelectItem(17,1);
      } else if(numberClick == 2) {
        numberClick = 3;
        selectItem(17,3);
        unSelectItem(17,2);
      } else {
        numberClick = 0;
        selectItem(17,1);
        unSelectItem(17,3);
      }
    }
    prevButtonState2 = buttonState2;
  } else if(buttonState3 == LOW && prevButtonState3 == HIGH) {
    Serial.println("Button 3");
    if(currentMenu == 1) {
      setTimePerDay();
    } else if(currentMenu == 3) {
      if(numberClick == 0) {
        numberClick = 1;
        selectItem(17,1);
      } else if(numberClick == 1) {
        numberClick = -1;
        selectItem(17,2);
        unSelectItem(17,1);
      } else if(numberClick == 2) {
        numberClick = -1;
        selectItem(17,3);
        unSelectItem(17,2);
      } else {
        numberClick = 0;
        selectItem(17,1);
        unSelectItem(17,3);
      }
//      selectItem(r,c);
    }
    prevButtonState3 = buttonState3;
  } else if(buttonState4 == LOW && prevButtonState4 == HIGH) {
    Serial.println("Button 4");
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
    }
    prevButtonState4 = buttonState4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;
  }
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
void setTimePerDayMenu() {
  lcd.clear();
  lcd.setCursor(10,0);
  lcd.print("DD/MM/YYYY");
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

