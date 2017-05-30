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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  lcd.init();
  lcd.begin(20, 4);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("DD/MM/YYYY");

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin2, LOW);
  digitalWrite(buttonPin3, LOW);
  digitalWrite(buttonPin4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  menu();
}

void menu() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
//  Serial.println("Menu");
  if(buttonState1 == HIGH) {
    Serial.println("Button1");
    menu1();
  } else if(buttonState2 == HIGH) {
    Serial.println("Button2");
  } else if(buttonState3 == HIGH) {
    Serial.println("Button3");
  } else if(buttonState4 == HIGH) {
    Serial.println("Button4");
  }
}
 void menu1() {
  lcd.clear();
    lcd.setCursor(16,0);
    lcd.print("Time");
    Serial.println("loop in menu");
    lcd.setCursor(0,1);
    lcd.print("1. 1 Time");
    lcd.setCursor(0,2);
    lcd.print("2. 2 Time");
    lcd.setCursor(0,3);
    lcd.print("3. 3 Time");
 }

