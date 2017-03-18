#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11 
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD
  Serial.begin(9600); 
//  Serial.println("DHTxx test!");

  dht.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.backlight();
  if (isnan(t) || isnan(h)) {
    
    Serial.println("Failed to read from DHT");
    
  } else {
//    Serial.print("Humidity: "); 
//    Serial.print(h);
//    Serial.print(" %\t");
//    Serial.print("Temperature: "); 
//    Serial.print(t);
//    Serial.println(" *C");
    lcd.setCursor(0,0);
    lcd.print("Temp = ");
    lcd.print(t);
    lcd.setCursor(0,1);
    lcd.print("Humidity = ");
    lcd.print(h);  
  }
}
