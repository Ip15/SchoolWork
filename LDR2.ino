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
  if (val < 400)
  digitalWrite (9, LOW);
  else
   digitalWrite (9, HIGH);
  }
