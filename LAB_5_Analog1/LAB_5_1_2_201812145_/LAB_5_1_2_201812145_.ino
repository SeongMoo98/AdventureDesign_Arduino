//A0핀에 가변저항 연결
int vRegister=A0;
//LED연결핀
int pins_LED[]={2,3,4,5};

void setup() {
  Serial.begin(9600);
  //가변저항을 INPUT모드
  pinMode(vRegister,INPUT);
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i],OUTPUT);
    digitalWrite(pins_LED[i],LOW);
  }

}

void loop() {
  //가변저항 값 읽기
  int adc=analogRead(vRegister);
  
  //LED개수 결정
  int count_led=(adc>>8)+1;
  //LED 점멸
  for(int i=0; i<4; i++){
    if(i<count_led){
      digitalWrite(pins_LED[i], HIGH);
    }
    else{
      digitalWrite(pins_LED[i],LOW);
    }
  }
  //ADC값과 LED개수 출력
  Serial.println(String("ADC : ")+adc+", LED count : "+count_led);
  delay(1000); 
  

}
