#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

int currentMenu = 0;
int numberClick = 0;

#define btnNone 0;
#define btn1 1;
#define btn2 2;
#define btn3 3;
#define btn4 4;

int buttonPush = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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
}
int read_LCD_buttons() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if(buttonState1 == 1) {
    Serial.println("Button 1");
    return btn1;
  } else if(buttonState2 == 1) {
    Serial.println("Button 2");
    return btn2;
  } else if(buttonState3 == 1) {
    Serial.println("Button 3");
    return btn3;
  } else if(buttonState4 == 1) {
    Serial.println("Button 4");
    return btn4;
  }
//  } else {
//    return btnNone;
//  }
}
void loop() {
  // put your main code here, to run repeatedly:
//  statusMenu(); 
//  Serial.println("============ .   ");
//  Serial.print(buttonPush);
  buttonPush = read_LCD_buttons();
  switch (buttonPush) {
  case 1:
    // statements
    Serial.println("Case 1");
    intoMenu();
    currentMenu = 1;
//    if(currentMenu == 0) {
//      Serial.println("CurrentMenu = 0");
//      buttonPush = 0;
//      lcd.clear();
//    }
    break;
  case 2:
    // statements
    Serial.println("Case 2");
    if(currentMenu == 1) {
      Serial.println("Down");
      if(numberClick == 0) {
        numberClick += 1;
        selectItem(19,1);
        unSelectItem(19,3);
      } else if(numberClick == 1) {
        numberClick += 1;
        selectItem(19,2);
        unSelectItem(19,1);
      } else if(numberClick == 2) {
        numberClick += 1;
        selectItem(19,3);
        unSelectItem(19,2);
      } else {
        numberClick = 0;
      }
    }
    break;
  default: 
    // statements
    Serial.println("Case Default");
    statusMenu(); 
//    currentMenu = 0;
  break;
  }

}
void statusMenu() {
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DD/MM/YYYY");
  lcd.setCursor(14,0);
  lcd.print("12:12");
  lcd.setCursor(0,3);
  lcd.print("Menu");
}
void intoMenu() {
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("==== MAIN MENU ====");
  lcd.setCursor(0,1);
  lcd.print("1. Set Date");
  lcd.setCursor(0,2);
  lcd.print("2. Time Per Day");
  lcd.setCursor(0,3);
  lcd.print("3. Weight Per Time");
}
void selectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print("<");
}
void unSelectItem(int r, int c) {
  lcd.setCursor(r,c);
  lcd.print(" ");
}
