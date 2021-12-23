//14 15 - 풀 다운 16 17 - 풀업 저항
int buttons[] = {14, 15, 16, 17}; //버튼 연결 핀
void setup() {
 Serial.begin(9600);
 for(int i=0; i < 4; i++){
  pinMode(buttons[i], INPUT); //버튼 연결 핀을 입력으로 설정
 }
}

void loop() {
  for(int i = 0; i < 4; i++){
    Serial.print(digitalRead(buttons[i])); //버튼 상태 출력
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);

}
