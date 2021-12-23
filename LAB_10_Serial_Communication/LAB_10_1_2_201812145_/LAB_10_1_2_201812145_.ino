//mySerial(4, 5) - RX : 4, TX : 5 
//Serial1        - TX : 18, RX : 19 통신
int LED_pins[] = {2, 3, 4, 5};
int num_LED = 0;
int delta = 1;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600); //다른 Mega2560과 통신하는 Serial1객체
  for(int i=0; i < 4 ; i++){
    pinMode(LED_pins[i],OUTPUT);
    digitalWrite(LED_pins[i],LOW);
  }
}

void loop(){
  //mySerial.write('1')
  if(Serial1.available()){
    char data = Serial1.read();
    if(data == '1'){
      num_LED += delta;
      if(num_LED == 5){
        delta = -1;
        num_LED = 3;
      }
      else if(num_LED == -1){
        delta = 1;
        num_LED = 1;
      }
      Serial.print("Currntly");
      Serial.print(num_LED);
      Serial.println("LEDs are ON.");
      for(int i=0; i<4; i++){
        if(i<num_LED)
          digitalWrite(LED_pins[i],HIGH);
        else
        digitalWrite(LED_pins[i],LOW);
      }
    }
  }
}
