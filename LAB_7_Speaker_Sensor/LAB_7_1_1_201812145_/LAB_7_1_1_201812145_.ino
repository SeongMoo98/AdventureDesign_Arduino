#include <pitches.h>
int speakerPin=57; //스피커 연결핀
//int speakerPin=A3;

//매크로 선언(음표)
//도  레  미  파  솔  라  시  도
//G4 D4  E4  F4 G4  A4  B4 C5 . . . .   
int melody[] = { // 학교 종 멜로디, 0은 쉼표
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0, 
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, 0
};

int noteDuration = 4; // 4분 음표

void setup() {
}

void loop() {
  for(int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++){
    int noteLength = 1000 / noteDuration; 
    tone(speakerPin, melody[thisNote], noteLength);
    delay(noteLength);
    noTone(speakerPin); //현재 음 재생중지
  }
  while(true);
  
}
