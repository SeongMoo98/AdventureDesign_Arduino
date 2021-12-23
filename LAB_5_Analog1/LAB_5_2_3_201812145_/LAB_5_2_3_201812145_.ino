int pins_LED[]={2,3,4,5};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i],OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  int ADC_value = analogRead(A0);
  int PWM_value[4] = {0, };
  Serial.println(String("ADC value : ")+ADC_value);

  //4개 LED의 밝기로 나눔
  for(int i=3; i>=0; i--){
    if(ADC_value>=256 * i){
      //PWM 은 0~255
      PWM_value[i] = ADC_value - 256 * i;
      //이건 뭐고
      ADC_value -= (PWM_value[i]+1);
    }
    //LED 밝기 조절
    analogWrite(pins_LED[i], PWM_value[i]);
    Serial.print(" ");
    Serial.print(PWM_value[i]);
  }
  Serial.println();
  delay(500);
}
