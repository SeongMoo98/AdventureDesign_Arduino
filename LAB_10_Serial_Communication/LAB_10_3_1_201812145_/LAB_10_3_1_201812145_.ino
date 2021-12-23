//I2C통신 - slave를 소프트웨어적인 '주소'에 의해 구별
//주소는 #define으로 지정
//Wire라이브러리 - 마스터모드 슬레이브 모드 모두 지원
//Wire Library
//Wire.begin(), Wire.available(), Wire.read(), Wire.write(data), Wire.write(const uint8_t* data, size_t quantity)

//Wire.available()
//수신 버퍼의 유효 바이트수 return

//Wire.read()
//수신 버퍼의 한 바이트를 읽어서 반환

//Wire.write(uint8_t data)
//data - 전송할 단일 byte
//==>byte로 변환해 줄 필요가 있다

//Wire.write(const uint8_t* data, size_t quantity)
//data - 전송할 바이트 배열에 대한 포인터, quantity - 전송할 바이트 수

//마스터
//Wire.beginTransmission(unit8_t address)
//address - slave주소 ==> 통신 시작

//Wire.endTransmission(void) Wire.endTransmission(unit_t sendStop)
//sendStop - 요청 완료 후 정지메시지 전송 여부
//endTransmission해야 실제 데이터 전송

//Wire.requestFrom(uint8_t address, uint8_t quantity)
//Wire.requestFrom(uint*-t address, uint8_t quantity, uint8_t sendStop)
//슬레이브로 데이터를 요청 ==> 슬레이브에서 write해주면 ==> read()
//슬레이브로부터 전송된 바이트 수 return

#include<Wire.h>
#define SLAVE 4 //Slave address

void setup() {
  //I2C 통신을 위한 Wire라이브러리 초기화, 마스터인 경우 주소 불필요
  //==>Slave는 주소가 필요하다
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  i2c_communication();
  delay(1000);
}

void i2c_communication(){
  10011100010000
  //reading = 10000이라 해보자
  //0x2710 - 0010 0111 0001 0000
  int reading = analogRead(A0);
  
  Wire.beginTransmission(SLAVE);
  //int값을 byte로 바꾸기
  //int는 2byte라 1바이트씩 쪼개서 전송
  Wire.write(reading >> 8); //1byte 0010 0111
  Wire.write(reading & 0xFF);  //1byte 0001 0000
  Wire.endTransmission(SLAVE); //실제 데이터 전송

  Serial.print("I send ");
  Serial.println(reading);
}
