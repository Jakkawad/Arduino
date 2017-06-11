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
int buttonKey = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonKey = read_LCD_Button();
  switch (buttonKey) {
    case 1: {
      Serial.println("Button 1");
      break;
    }
    case 2: {
      Serial.println("Button 2");
      break;
    }
    case 3: {
      Serial.println("Button 3");
      break;
    }
    case 4: {
      Serial.println("Button 4");
      break;
    }
    case buttonNone: {

      break;
    }
  }

}
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
