//가변저항값에 따른 interval(모터속도 조절)
#include <Servo.h>
Servo myServo;
int servoPin = 11;
unsigned long time_previous, time_current;

int interval = 10; // 현재 이동 시간 간격
int angle = 0; // 현재 모터의 각도
int angle_step = 1; // 모터 각도의 증감(1 or –1)

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin); //서보모터 연결
  myServo.write(angle); //0도에서 시작
  delay(100);
  time_previous=millis();
}

//가변저항 값이 크면 interval이 커져 서보모터가 천천히 회전
//가변저항 값이 작으면 interval이 작아져 서보모터가 빠르게 회전
void loop() {
  time_current=millis();
  if(time_current - time_previous >= interval){
    time_previous = time_current;
    angle += angle_step; // 현재 각도 조정
    //180도를 넘어가면 방향 전환(angle에 더해주는 angle_step의 방향을 바꿔줌)
    if(angle > 180) { 
      angle = 180;
      angle_step *= -1;
    }
    else if(angle < 0) { // 0도를 넘어가면 방향전환
      angle=0;
      angle_step *= -1;
    }
    myServo.write(angle);
  }

  int reading = analogRead(A0);
  int new_interval = map(reading, 0, 1023, 5, 20);
  if(new_interval != interval){
    interval = new_interval; //이동시간 간격 조정
    Serial.print("Currrent Interval : ");
    Serial.println(interval);
  }
}
