#include <LiquidCrystal.h>
// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

// 사용자 정의 문자 데이터 - 5 x 8 - 8개의 문자 정의 가능(주소 0 ~ 7)
byte user1[8] = {
  0B00000,
  0B10001, 
  0B00000, 
  0B00000, 
  0B10001,
  0B01110,
  0B00000,
  0B00000
};
byte user2[8] = {
  0B00000,
  0B10001,
  0B01010, 
  0B10001, 
  0B00000, 
  0B10001,
  0B01110, 
  0B00000
};

void setup() {
  //0이랑 1은 뭐고 - Location : byte(n) - (0~7) 
  lcd.createChar(0, user1); //사용자 정의 문자 1 생성
  lcd.createChar(1, user2); //사용자 정의 문자 2 생성
  lcd.begin(16,2);
  lcd.clear();

  lcd.write(byte(0)); //사용자 정의 문자 1 출력
  lcd.setCursor(0,1);
  lcd.write(byte(1)); //사용자 정의 문자 2 출력
}

void loop() { }
