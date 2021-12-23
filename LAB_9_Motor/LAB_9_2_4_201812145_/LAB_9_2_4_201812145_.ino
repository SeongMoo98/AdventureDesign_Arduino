//가변저항으로 모터 속도제어
int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  Serial.begin(9600);

}

void loop() {
  int reading = analogRead(A0);
  //512에서 방향이 바뀐다
  int speed = map(reading, 0, 1023, -255, 255);

  // reading = 512 ==> speed = 1
  if(speed > 0){
    digitalWrite(DIR1, HIGH); //정방향 회전
    //가변저항이 커지면 pwm_value가 작아짐 ==> 속도가 서서히 증가
    int pwm_value = 255 - speed;
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading);
    Serial.println(String(", Clockwise : ") + speed);
  }
  else{
    digitalWrite(DIR1, LOW); //역방향 회전
    //가변저항이 작아지면 pwm_value가 커짐 == > 속도 서서히 증가
    int pwm_value = abs(speed);
    analogWrite(PWM1, pwm_value);
    Serial.print(String("Reading : ") + reading);
    Serial.println(String(", Anti-clockwise : ") + pwm_value);
  }
  delay(1000);
}
