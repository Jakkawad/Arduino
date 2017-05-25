#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);

const int buttonPin1 = 2;
const int buttonPin2 = 3;

const int ledPin = 13;

int buttonState1 = 0;
int buttonState2 = 0;

int prevButtonState1;
int prevButtonState2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin2, LOW);

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
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
  }
//  buttonState = digitalRead(buttonPin);
//  if(buttonState == HIGH) {
//    digitalWrite(ledPin, HIGH);
//  } else {
//    digitalWrite(ledPin, LOW);
//  }

}
