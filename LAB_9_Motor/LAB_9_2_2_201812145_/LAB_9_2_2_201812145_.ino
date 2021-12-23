//DC모터의 회전속도 조절
//모터 1
int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;

void setup() {
  pinMode(Enable1, OUTPUT);
  digitalWrite(Enable1, LOW); // 모터 제어 불가능 상태
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
}

void loop() {
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, HIGH); // 정방향 회전
  //정방향회전에서 모터 속도 서서히 증가(HIGH -> LOW ==> 255 -> 0 )
  //analogWrite사용 - PWM
  for(int i=255; i >= 0; i--){
    analogWrite(PWM1, i); 
    delay(30);
  }
  digitalWrite(PWM1, HIGH); //모터 정지

  delay(200);
  
  //역방향회전에서 모터 속도 서서히 증가( LOW -> HIGH ==> 0 -> 255 )
  digitalWrite(DIR1, LOW); //역방향 회전
  for(int i=0; i<=255; i++){
    analogWrite(PWM1, i);
    delay(30);
  }
  digitalWrite(PWM1, HIGH); //모터 정지
  delay(200);
  
}
