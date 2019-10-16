void setup() {
    pinMode(7, INPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}
void loop(){
    if(digitalRead(7) == 1){
        digitalWrite(13, HIGH);
        Serial.println("Wire voltage is 5v");
    }
    else{
        digitalWrite(13, LOW);
        Serial.println("Wire voltage is 0v");
    }
}