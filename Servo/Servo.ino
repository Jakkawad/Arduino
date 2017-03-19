#include <Servo.h>

Servo servo;

int pos = 0;
void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for(pos = 0; pos < 180; pos += 1) {
//    servo.write(pos);
//    delay(15);
//  }
//  for(pos = 180; pos >= 1; pos -= 1) {
//    servo.write(pos);
//    delay(15);
//  }
  servo.write(10);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(170);
  delay(1000);
}
