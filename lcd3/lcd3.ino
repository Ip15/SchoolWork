//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
}

int i=1;
void loop()
{
  for(i=1;i<101;i++){
  lcd.setCursor(0,0);
  lcd.print(i);
  if(i%2){
    lcd.setCursor(0,1);
    lcd.print("Even");
  }else{
    lcd.setCursor(0,1);
    lcd.print("Odd");
    }
  delay(3000);
  lcd.clear();
  }
}
