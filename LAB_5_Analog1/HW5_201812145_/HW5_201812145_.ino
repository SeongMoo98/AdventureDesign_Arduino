/*
 * HW5_201812145
 * PWM신호를 사용하여 LED 밝기 조절
 * 각 LED의 시작 밝기가 다름
 * 0%, 25%, 50%, 100%로 시작
 */
int pins_LED[]={2,3,4,5};
//0%, 25%, 50%, 100%로 시작
int PWM_value[] = {0,63,127,191};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i],OUTPUT);
  }
}

void loop() {
   while(true){
    for(int j=0; j<4; j++){
      PWM_value[j] += 1;
      if(PWM_value[j] >= 256){
        PWM_value[j]=0;
      }
      analogWrite(pins_LED[j], PWM_value[j]);
    }
    delay(10);
  } 
}
