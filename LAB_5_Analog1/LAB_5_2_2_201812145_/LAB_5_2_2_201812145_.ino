int pins_LED[]={2,3,4,5};

void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i],OUTPUT);
  }
  //가변저항 연결 핀 입력으로 설정
  pinMode(A0,INPUT);

}

void loop() {
  //ADC 값
  int ADC_value = analogRead(A0);
  //PWM 값
  int PWM_value = ADC_value >> 2;
  //ADC 값은 10bit PWM 값 8 bit

  Serial.print(String("ADC value : ") +ADC_value);
  Serial.println(String(", PWM value : ")+PWM_value);
  for(int i=0; i<4; i++){
    analogWrite(pins_LED[i], PWM_value);
  }
  delay(1000);

  

  
}
