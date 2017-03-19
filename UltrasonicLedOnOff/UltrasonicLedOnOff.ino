#include <Ultrasonic.h>

int redLed = 7;
int blueLed = 6;
Ultrasonic ultrasonic(9,8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
//  pinMode(blueLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(ultrasonic.Ranging(CM));
//  Serial.println(" cm");
  if (ultrasonic.Ranging(CM) <= 10) {
//    analogWrite(redLed, HIGH);
    digitalWrite(redLed, HIGH);
    Serial.println(" <= 10");
  } else {
//    analogWrite(redLed, LOW);
    digitalWrite(redLed, LOW);
    Serial.println(" >= 10");
  }
//  analogWrite(redLed, HIGH);
//  digitalWrite(redLed, HIGH);
//  analogWrite(redLed, LOW);
  delay(100);
}
