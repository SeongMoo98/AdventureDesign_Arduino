//가변저항으로 LED의 점멸 간격 조절
//가변저항이 커지면 interval 증가 -> 점멸간격 길어짐
int pin_LED = 2; //LED 연결 핀
unsigned long time_previous, time_current;
unsigned long interval = 1000; //점멸 간격
boolean LED_state = false;

void setup() {
  pinMode(A0, INPUT);
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LED_state);
  Serial.begin(9600);
  time_previous = millis(); //현재 시간
}

void loop() {
  time_current = millis();
  if(time_current - time_previous >= interval){
    Serial.print("Current interval is ");
    Serial.print(interval);
    Serial.println(" ms.");
    //시작 시간 갱신
    time_previous = time_current;
    LED_state = !LED_state;
    digitalWrite(pin_LED, LED_state);
  }
  //가변저항 읽기
  int adc= analogRead(A0);
  //점멸 간결으로 변환 - 0.5 ~ 1.5초 사이의 시간으로 매핑
  interval = map(adc, 0, 1023, 500, 1500);
}
