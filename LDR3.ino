int val;
void setup() 
  {
    pinMode(A0, INPUT);
    pinMode(9, OUTPUT);
    Serial.begin (9600);
  }
  void loop () {
  val = analogRead (A0);
  Serial.println (val);
  Serial.println(val*5/1024.00);
  if (val < 400){
  analogWrite(9, val);
  }else{
   analogWrite(9, val);
  }
  }
