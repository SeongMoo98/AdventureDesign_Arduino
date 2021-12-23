void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int n=123;
  float f=3.1415927;

  //2진수 출력
  Serial.println(n,BIN);
  
  //10진수 출력(디폴트 값으로 생략가능)
  Serial.println(n,DEC);
  //16진수 출력
  Serial.println(n,HEX);

  Serial.println();
  Serial.println(f);
  Serial.println(f,5);

  while(true);
}
