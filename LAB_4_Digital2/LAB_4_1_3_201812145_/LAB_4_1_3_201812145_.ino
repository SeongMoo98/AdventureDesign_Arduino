void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1, len = 0;
 
  //출력버퍼
  char buffer[128];
  while(true)
  {
    if(state == 1)
    {
      Serial.print("Enter a String ==>");
      state = 0;
    }
    //입력이 있으면
    while(Serial.available())
    {
      char data = Serial.read();
      //개행문자를 만날 때까지 읽음 ==> 시리얼 모니터에서 전송시 새줄 제어문자를 전송하도록 설정해야함
      //개행문자가 아니라면 buffer에 저장 
      if(data == '\n')
      {
        //버퍼의 마지막을 '\0' ==>하나의 문자배열이 만들어진다
        buffer[len] = '\0';
        String in_str = buffer; //buffer의 data에서 \0까지 String 생성
        Serial.println(in_str+" ["+in_str.length()+"]");
        state = 1;
        len = 0;
        break;
      }
      else
      {
        buffer[len++]=data;
      }
     
    }
  }

  
}
