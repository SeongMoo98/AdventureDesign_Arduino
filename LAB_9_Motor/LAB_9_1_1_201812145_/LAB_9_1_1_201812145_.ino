//서보모터
//PWM신호로 위치 제어(50Hz) PWM 신호 사용 : 20ms 주기 
//0~180도 회전 가능 - 정확한 위치제어 가능
#include <Servo.h> //표준 라이브러리
Servo myServo;
int servoPin = 11;

void setup() {
  myServo.attach(servoPin); //서보모터 연결
}

void loop() {
  int angle;
  for(angle=0; angle < 180; angle++){
    myServo.write(angle);
    delay(5);
  }

  for(angle=180; angle>0; angle--){
    myServo.write(angle);
    delay(5);
  }

}
