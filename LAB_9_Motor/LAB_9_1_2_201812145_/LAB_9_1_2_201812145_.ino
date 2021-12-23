//가변저항으로 서보모터 제어
#include <Servo.h>
Servo myServo;
int servoPin = 11;

void setup() {
  myServo.attach(servoPin); //서보모터 연결
}

void loop() {
  int value=analogRead(A0);
  int angle = map(value,0,1023,0,180); 
  myServo.write(angle);
}
