void setup() {
  Serial.begin(9600);

}

void loop() {
  String str1 = "One string", str2 = "Another String";
  int n = 1234;
  float f = 3.14;
  char c = 'A';
  
  //String 출력
  Serial.println(str1); 
  //문자열 연결
  Serial.println(str1 +" "+ str2);
  //정수와 진법 결정
  Serial.println(String(n));
  Serial.println(String(n,BIN));
  Serial.println(String(n,HEX));

  //Serial.println(String(f));
  Serial.println(f);

  //다른 타입의 데이터를 연결하여 새로운 Stirng 객체를 생성.
  //String 객체들만 + 연산자로 concatenation 할 수 있다.
  Serial.println("String + Integer : " +String(n));
  String str3="String + Character : ";
  str3 += 123;
  Serial.println(str3);
  
  //이건 에러가 난다
  //Serial.println("Stirng + Integer : "+1234);

  while(true);

}
