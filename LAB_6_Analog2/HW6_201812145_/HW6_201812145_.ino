/* HW6_201812145
 * 가변저항으로 LED의 점멸속도 제어
 * 가변저항의 값이 커지면 2번 LED의 점멸속도는 빨라지고 3번 LED의 점멸속도는 느려짐
 */
int pin_LED[]={2,3};  //2번 3번핀에 연결
unsigned long time_previous[2],time_current[2];
unsigned long interval[] = {1000,1000}; //점멸 간격
boolean LED_state[] = {false,false}; 

void setup() {
  pinMode(A0, INPUT);
  pinMode(pin_LED[0], OUTPUT);
  digitalWrite(pin_LED[0], LED_state[0]);
  pinMode(pin_LED[1], OUTPUT);
  digitalWrite(pin_LED[1], LED_state[1]);
  Serial.begin(9600);
 time_previous[0] = millis(); //현재 시간
 time_previous[1] = millis();
}

void loop() {
  //2번핀 LED
  time_current[0] = millis();
  if(time_current[0] - time_previous[0] >= interval[0]){
    Serial.print("Current interval(pin2) is ");
    Serial.print(interval[0]);
    Serial.println(" ms.");
    //시작 시간 갱신
    time_previous[0] = time_current[0];
    LED_state[0] = !LED_state[0];
    digitalWrite(pin_LED[0], LED_state[0]);
  }
  
  //3번핀 LED
  time_current[1]=millis();
  if(time_current[1] - time_previous[1] >= interval[1]){
    Serial.print("Current interval(pin3) is ");
    Serial.print(interval[1]);
    Serial.println(" ms.");
    //시작 시간 갱신
    time_previous[1] = time_current[1];
    LED_state[1] = !LED_state[1];
    digitalWrite(pin_LED[1], LED_state[1]);
    Serial.println();
  }
  
  
  int adc=analogRead(A0);
  //점멸 간결으로 변환 - 0.5 ~ 1.5초 사이의 시간으로 매핑
  interval[0] = map(adc, 0, 1023, 1500, 500); //-가변저항이 커질수록 2번핀 점멸간격 작아짐
  interval[1] = map(adc, 0, 1023, 500, 1500); //-가변저항이 커질수록 3번핀 점멸간격 길어짐
}
