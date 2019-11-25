#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define TrigPin 10
#define EchoPin 13

float distance, duration;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(EchoPin, INPUT);
  pinMode(TrigPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(EchoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  Serial.print("Distance = ");
  lcd.setCursor(1,1);
  lcd.print("Distance = ");
  
  if (distance >= 500 || distance <= 3) {
     Serial.println("Out of range");
     lcd.setCursor(1,1);
     lcd.print("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    lcd.setCursor(1,2);
    lcd.print(distance);
    lcd.setCursor(8,2);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
}
