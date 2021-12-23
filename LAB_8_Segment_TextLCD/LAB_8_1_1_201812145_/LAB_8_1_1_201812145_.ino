//Common Cathod Type
// 0에서 9까지 숫자 표현을 위한
// 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
  //0    1      2     3     4     5     6     7     8    9
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀

// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};

void setup() {
  //자릿수 선택 핀도 OUTPUT으로 해야하구나
  for (int i = 0; i < 4; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  
  for (int i = 0; i < 8; i++) {
    //bitRead는 LSB부터 읽으므로 역순으로 읽어줘야 한다
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

void loop() {
  //0~9까지 출력
  for (int no = 0; no < 10; no++) {
    for (int pos = 1; pos <= 4; pos++) {
      show_digit(pos, no); // ‘pos’ 자리에 숫자 ‘no’를 표시
      delay(200);
    }
  }
}
