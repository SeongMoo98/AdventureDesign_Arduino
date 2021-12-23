//LED 연결 핀
int pins_LED[] = {2, 3};
//버튼 연결 핀 ( 15 : 풀 다운 저항, 16 : 풀업 저항)
int pins_button[] = {15, 16};

//점멸 패턴                          풀다운 저항      풀업 저항
boolean on_off_patterns[2][2] = { {false, true}, {true, false} }; 

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; i++){
    //버튼 연결 핀을 입력으로 LED 연결 핀을 출력으로 설정
    pinMode(pins_button[i], INPUT);
    pinMode(pins_LED[i], OUTPUT);
  }
}


void loop() {
  for(int i = 0; i < 2; i++){
    //버튼 상태 읽기
    boolean state = digitalRead(pins_button[i]);
    //LED출력
    //state - 풀다운 저항 - 안눌려졌으면 0 눌려졌으면 1 
    //        풀업 저항 - 안눌려졌으면 1 눌려졌으면 0
    digitalWrite(pins_LED[i], on_off_patterns[i][state]);
    Serial.print(on_off_patterns[i][state]);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);

}
