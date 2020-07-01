#include <VirtualWire.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int transmit_pin = 12;
 
 String str;
 char cstr[100];
String message = "";
unsigned int mlength; // message length 
 
// for joystick
 int flag = 0; 
int buttonf = 0; 
int power = 7;
//int powers =8; 
int button = 4; 
int vrx = A1; 
int vry = A2;
 
 int xdata = 0; 
 int ydata = 0; 
void setup()
{
  /*
  lcd.init();
  lcd.init();
  lcd.backlight();
  */
      // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
     vw_setup(2000);       // Bits per sec
  Serial.begin(9600);
  
  pinMode(vrx, INPUT); 
  pinMode(vry, INPUT); 
  pinMode(power, OUTPUT); 
  //pinMode(powers, OUTPUT);
  digitalWrite(power, HIGH);
  //digitalWrite(powers, HIGH); 
 
  pinMode(button, INPUT); 
  digitalWrite(button , HIGH);
}
 
void loop()
{
  control();
 
   if( buttonf == 1)
   {
  xdata = analogRead(vrx); 
  ydata = analogRead(vry); 
  //lcd.setCursor(0,0);
  //lcd.print(xdata);
  //lcd.print(ydata);
 Serial.println(xdata);
 Serial.println(ydata);
SendData(xdata,ydata,buttonf); 
delay(100);
   }
   
   if(buttonf == 0)
   {
    SendData(0,0,0); // send 0 to the receiver.
    delay(100); 
   }
                
}
 
// this function takes 5 arguments as the input
// the sensors and the sensors group number. 
// let's say we are using multiple sensors, the sensors 
//can be divided into groups. 
void SendData( int xvalue,int yvalue,int buttonstatus)
{
 
message = message + xvalue +"," + yvalue + "," + buttonstatus ;
mlength = message.length(); // find the number of characters in a message.
  str = message;
  str.toCharArray(cstr,100);
  vw_send((uint8_t *)cstr, mlength); // 
  vw_wait_tx(); // Wait until the whole message is gone
  str = "";
  message = ""; 
 
}
 
 
void control()
{
if (( digitalRead(button) == LOW ) && (buttonf == 0))
{
 //lcd.print("  Started");
   Serial.println(" Started");  
  buttonf = 1; 
  delay(1000);
 
}
 
if (( digitalRead(button) == LOW ) && (buttonf == 1))
{

//lcd.print("ended");
  Serial.println("ended"); 
  buttonf = 0; 
  delay(1000); 
}
 digitalWrite(button , HIGH);
}
