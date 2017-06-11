int relay1 = 35;
int relay2 = 36;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay1, 0);
  Serial.println("0");
  delay(4000);
  digitalWrite(relay1, 1);
  Serial.println("1");
  delay(4000);
}
