int val;
void setup() 
  {
    pinMode(A0, INPUT);
    pinMode(13, OUTPUT);
    Serial.begin (9600);
  }
  void loop () {
  val = analogRead (A0);
  Serial.println (val);
  if (val < 600)
  digitalWrite (13, LOW);
  else
   digitalWrite (13, HIGH);
  }
