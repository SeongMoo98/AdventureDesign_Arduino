int led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH); //13번 pin으로 HIGH(1 or ON) 출력
  delay(1000);  //1초(1000ms) 대기
  digitalWrite(led,LOW);  //13번 pin으로 LOW(0 of OFF) 출력
  delay(1000);

  
}
