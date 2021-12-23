//마스테에서 송신한 데이터 슬레이브에서 수신, 출력
//I2C통신 - Slave
//Slave Method

//void onReceive(void(*)(int))
//슬레이브가 마스터로부터 전송을 받을 떄 호출할 기능을 등록 
//==>등록한 함수의 parameter로 마스터에서 읽은 바이트수를 사용
//parameter - 반환형이 void이고 매개변수는 int한개인 함수 포인터

//void onRequest(void(*)(void))
//마스터가 이 슬레이브 장치에 데이터를 요청할 때 호출할 함수
//매개변수와 반환형 둘다 없다
////ex) 
//void handler(){
//  Wire.write('1');
//}
//이런식으로 마스터의 버퍼에 Write해준다


#include<Wire.h>
#define SLAVE 4

void setup() {
  //Wire 라이브러리 초기화, 슬레이브로 참여하기 위해서는 주소를 지정해야 한다
  Wire.begin(SLAVE);
  //마스터의 데이터를 수신했을 때 처리할 함수등록(함수포인터)00
  Wire.onRecieve(receiveFromMaster);
  Serial.begin(9600);
}

void loop() {
}


//parameter - 마스터에서 보낸 byte 수
//마스터에서 보낸 값 - 수신버퍼에 존재 0x2710 - 0010 0111 0001 0000
void receiveFromMaster(int bytes){
  //2byte정수값 읽기
  byte r1 = Wire.read(); //r1 = 0010 0111 - 앞에 1byte
  byte r2 = Wire.read(); //r2 = 0001 0000 - 남은 1byte

  int value = (r1<<8) + r2;

  Serial.print("I got");
  Serial.println(value);
  
}
