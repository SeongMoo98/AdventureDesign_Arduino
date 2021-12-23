// A0핀(아날로그 입력 핀)에 가변저항 연결
int vRegister=A0; 
  
void setup() {
  Serial.begin(9600);
  pinMode(vRegister,INPUT);
}

void loop() {
  //가변저항의 값을 읽어 출력
  Serial.println(analogRead(vRegister));
  delay(1000);
}
