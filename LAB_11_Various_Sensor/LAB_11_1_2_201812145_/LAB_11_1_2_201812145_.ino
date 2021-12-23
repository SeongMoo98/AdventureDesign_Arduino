//초음파 센서(HC-SR04 Ultrasonic sensor)
//초음파 센서 값 출력
//Trigger pin - digitalWrite로 HIGH를 주면 초음파를 쏨, LOW를 주면 중지 
//Ecno pin - Trigger에서 US wave를 쏘면 HIGH ==> Echo pin에서 수신할때까지 HIGH를 유지하다 수신하면 LOW

//pulseIn(pin, value, timeout) - pin이 value가 될때까지 timeout동안 기다리고 그 시간안에 pin이 value값이 안되면 0리턴
//ex)pulseIn(echoPin, HIGH, 3);
//Echo pin의 pulse를 읽음 ==> Echo pin의 pulse가 HIGH가 될때까지(최대 3초) 기다림 
//==>HIGH가 안되면 return 0, HIGH가 되면 시간측정 시작하고 LOW가 되면 측정시간 return
//timeout Default value = 1s

int trigPin = 3;
int echoPin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH); 
  delay(10);
  digitalWrite(trigPin, LOW);
  
  //Reads the echoPin, returns the sound wave travel time in microseconds
  //Echo 출력이 HIGH가 되는 시점부터 LOW가 될때 까지 펄스폭의 시간을 측정 ==> HIGH를 유지한 시간 ==> 음속을 통해 거리계산
  float duration = pulseIn(echoPin, HIGH); 
  float distance = duration * 340 / 10000 / 2;
  Serial.println(String("Distance(cm): ") + distance);
  delay(500);
}
