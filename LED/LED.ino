int redLed = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLed, HIGH);
//  analogWrite(redLed, HIGH);
  delay(1000);
  digitalWrite(redLed, LOW);
//  analogWrite(redLed, LOW);
  delay(1000);
}
