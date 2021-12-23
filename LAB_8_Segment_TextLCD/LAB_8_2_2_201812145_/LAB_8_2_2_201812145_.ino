//임의의 위치에 문자표시
#include <LiquidCrystal.h>
// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

//setCursor 사용
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0); // 0행 0열로 이동
  lcd.write('1'); //문자단위 출력

  lcd.setCursor(5,0); // 5행 0열로 이동
  lcd.write('2'); 

  lcd.setCursor(0,1); 
  lcd.write('3');

  lcd.setCursor(5, 1); 
  lcd.write('4');
}

void loop() { }
