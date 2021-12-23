//버튼(풀다운)으로 방향 조절
int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int button_pin = 14;

boolean direction = true;

void setup() {
  pinMode(Enable1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  digitalWrite(Enable1, HIGH); // 모터 제어 가능 상태
  digitalWrite(DIR1, direction); // 초기 방향은 정방향
  digitalWrite(PWM1, !direction); // 최고 속도 - !direction으로 LOW
  pinMode(button_pin, INPUT);
  Serial.begin(9600);

}

void loop() {
  //버튼을 누르면 방향바꿔주기
  if(digitalRead(button_pin)){
    direction = !direction;
    if(direction)
      Serial.println("Clockwise..."); //시계방향
    else
      Serial.println("Anti-closewise"); //반시계방향
    digitalWrite(DIR1, direction);
    digitalWrite(PWM1, !direction);
    delay(2000);
  }

}
