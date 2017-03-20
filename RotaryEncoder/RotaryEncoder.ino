int pinA = 3;
int pinB = 4;
int encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;
void setup() {
  // put your setup code here, to run once:
  pinMode (pinA, INPUT);
  pinMode (pinB, INPUT);

  pinALast = digitalRead(pinA);
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  aVal = digitalRead(pinA);
  if (aVal != pinALast) {
    if (digitalRead(pinB) != aVal) {
      encoderPosCount ++;
      bCW = true;
    } else {
      bCW = false;
      encoderPosCount --;
    }
    Serial.print("Rotated: ");
    if (bCW) {
      Serial.println("clockwise");
    } else {
      Serial.println("counterclockwise");
    }
    Serial.print("Encoder Position: ");
    Serial.println(encoderPosCount);
  }
  pinALast = aVal;
}
