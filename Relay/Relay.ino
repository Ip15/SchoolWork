#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define realyPin 7


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.init();
  lcd.backlight();
  pinMode(realyPin, INPUT);
  

}
int a = digitalRead(realyPin);
void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(realyPin);
  if(a == HIGH){
    lcd.setCursor(1,1);
    lcd.print("Close");
    delay(3000);
    } else {
      lcd.setCursor(1,1);
      lcd.print("Open");
      delay(3000);
      }

}
