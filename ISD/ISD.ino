#define Rec 5
#define Play 7
void setup() {
  // put your setup code here, to run once:
  pinMode(Rec, INPUT);
  pinMode(Play, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Rec)==HIGH){
    digitalWrite(Rec,HIGH);
    }else{
      digitalWrite(Play,HIGH);
      }

}
