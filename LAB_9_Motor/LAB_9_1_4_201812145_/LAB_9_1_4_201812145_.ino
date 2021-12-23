//시리얼모니터로 서보모터 제어
#include <Servo.h>
Servo myServo;
int servoPin = 11;
String buffer = "";
boolean process_it = false;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  //시리얼 모니터에서 입력 값 읽기
  while(Serial.available()){
    char data = Serial.read(); 
    if(data == '\n'){   //'\n' 문자까지 문자열을 수신하여 처리
      process_it = true;
      break;
    }
    buffer += data;
  }
  
  if(process_it){ //문자열 처리
    process_it =false;
    //정수값으로 변환
    int angle = buffer.toInt(); 
    Serial.print(String(">> ") + buffer);
    //잘못된 각도 입력
    if(angle < 0 || angle > 180) { 
      Serial.print("... Invalid angle.");
    }
    else{
      Serial.println();
      myServo.write(angle);
      delay(3);
    }
  }
  buffer = "";  //버퍼 비움
}
