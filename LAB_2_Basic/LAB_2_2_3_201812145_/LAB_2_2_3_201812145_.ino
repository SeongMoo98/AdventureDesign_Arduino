void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0) //수신된 데이터의 존재 여부 확인
    byte data=Serial.read(); //바이트 단위로 읽기
  
  Serial.print("Echo back : ");
  Serial.write(data); //문자 출력
  Serial.print(" ");
  Serial.println(data); //ASCII값 출력
  } 
}
