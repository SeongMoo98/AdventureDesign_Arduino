/*
 * TouchSensor와 Alcohol Sensor를 이용한 음주탐지기
 * Touch 센서에서 터치를 감지하면 시동이 걸리는 상황
 * Alcohol Sensor로 계속 감지를 하면서 UART통신
 * Alcohol이 감지되거나 터치센서를 두번 누르면 종료
 */
#include<SoftwareSerial.h>
SoftwareSerial mySerial(4,5);
int touch_Sensor = 7;
int alcohol_Senseor A0

boolean previous_touch_state = false; 
boolean current_touch_state = false; 

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(alcohol_Senseor, INPUT);
  pinMode(touch_Sensor, INPUT); 
}

void loop() {
  current_touch_state = digitalRead(touch_Sensor);  
  if(current_touch_state == HIGH){
    while(1){
      int alcohol_value = analogRead(A0);
      Serial.println(alcohol_value);
      if(alcohol_value >= 100){ // 알코올 감지
        Serial.println("Alcohol Detached");
        mySerial.write('1');
      }
      else if(alcohol_value < 100){ // 계속 주행
        Serial.println("Continue");
        mySerial.write('3');
      }
      
      delay(100);
      
      previous_touch_state = current_touch_state;
      current_touch_state = digitalRead(touch_Sensor);
      //두번 터치되면 종료
      if(previous_touch_state == 0 && current_touch_state == 1){
        Serial.println("Thank you")l
        mySerial.write('2');
        exit(0);
      }
      
    }
  }
  delay(100);
}
