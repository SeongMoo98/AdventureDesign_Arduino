//적외선 센서(움직임 감지 센서) - Passive Infrared(PIR) Motion Sensor
//적외선 센서 값을 출력
//적외선 센서 - 적외선을 감지해서 전압으로 출력
//==>신체의 움직임을 인식
int motionPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
}
void loop() {
  int motion = digitalRead(motionPin);
  if(motion == 1) {
    Serial.println("Motion detected");
  }
  delay(500);
}
