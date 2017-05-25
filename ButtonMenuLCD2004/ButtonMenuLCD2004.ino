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
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  
  
  if(buttonState1 == LOW && prevButtonState1 == HIGH) {
    Serial.println("Button 1");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu 1");
    prevButtonState1 = buttonState1;
  } else if(buttonState2 == LOW && prevButtonState2 == HIGH) {
    Serial.println("Button 2");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu 2");
    prevButtonState2 = buttonState2;
  } else if(buttonState3 == LOW && prevButtonState3 == HIGH) {
    Serial.println("Button 3");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu 3");
    prevButtonState3 = buttonState3;
  } else if(buttonState4 == LOW && prevButtonState4 == HIGH) {
    Serial.println("Button 4");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu 4");
    prevButtonState4 = buttonState4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;
  }

void menu1() { 

}
  
}
