void setup() {
    pinMode(7, OUTPUT);
}
void loop() {
    for(int i=0; i<255; i++){
        analogWrite(7, i);
        delay(20);
    }
    for(int i=255;i>0;i--){
        analogWrite(7, i);
        delay(20);
    }

}