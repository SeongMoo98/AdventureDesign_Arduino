#include <LiquidCrystal.h>
#include <pitches.h>
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

#define speakerPin 57

int melody = NOTE_A4;
int noteDuration = 4;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0); // 0행 0열로 이동
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //UART통신을 통한 Text LCD 출력
  if(Serial1.available()){
    char data = Serial1.read();
    Serial.println(data);
    lcd.clear();
    if(data == '1'){ // 알코올 감지
      Serial.println("Alcohol Detached");
      lcd.print("Alcohol Detected");
      int noteLength = 5000 / noteDuration; 
      tone(speakerPin, melody, noteLength);
      delay(noteLength);
      noTone(speakerPin); 
      //종료
      Serial.println("종료");
      exit(0);
    }
    else if(data == '2'){ // 터치 2번에 종료
      Serial.println("Thank you");
      lcd.clear();
      lcd.print("Thank you");
      delay(3000);
      exit(0);
    }
    else if(data == '3'){
      lcd.print("Driving...");
    }
  }
}
