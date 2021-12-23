//UART(Universal Aynchronous Receiver/Transmission
//SoftwareSerial(RX, TX) 형식으로 메가2560의 핀과 교차하여 연결한다.
//SoftwareSerial mySerial(4, 5)
//4번핀은 다른 보드의 TX(18)번에 연결, 5번 핀은 다른 보드의 RX(19)번에 연결
//==>다른 보드에서는 18(TX), 19(RX)를 사용하는 Serial1객체 사용
#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5);

int button_pin = 2;
boolean previous_state = false;

void setup() {
  mySerial.begin(9600); // 메가2560과의 시리얼 연결
  Serial.begin(9600); // 컴퓨터와의 시리얼 연결
  pinMode(button_pin, INPUT);
}

void loop() {
  boolean state = digitalRead(button_pin); // 버튼 읽기  
  if (state) { // 버튼이 눌러진 경우
    // 눌러지지 않은 상태에서 눌러진 경우로 상태가 바뀐 경우
    //버튼을 한번 누를때마다 Mega2560 Serial1의 버퍼에 Write('1') 
    if (previous_state == false) {
      mySerial.write('1');
      Serial.println("Button is pressed...");
    }
    previous_state = true;
    delay(20);
  }
  else {
    previous_state = false;
  }
}
