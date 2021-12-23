#include <LiquidCrystal.h>
//핀번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); //LCD연결 - LCD 객체 생성
void setup() {
  lcd.begin(16, 2); //lcd객체를 16열 2행으로 초기환
  lcd.print("Hello World!"); //문자열 출력
}

void loop() {
}
