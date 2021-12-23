//SPI통신(Serial Peripheral Interface)
//하드웨어적으로 지원되는 통신 
//SCK(Serial Clock) - 동기통신을 위한 클록
//MISO(Master Output(Out) Slave Input(In)) - 데이터 송수신
//MOSI(Master Input(In) Slava Output(Out)) - 데이터 송수신
//SS(Slave Select) - 슬레이브 선택

//하드웨어 통신
//MISO(50), MOSI(51), SCK(52)는 전용핀으로 통신
//SS - Slave선택(LOW) 53번핀

//마스터에서 슬레이브로 메시지 보내기
#include<SPI.h>
int SS_arduino = 53;
int SS_EEPROM = 42; //??
void setup() {
  pinMode(SS_arduino, OUTPUT);  //마스터에서 슬레이브를 선택한다
  pinMode(SS_EEPROM,OUTPUT);
  digitalWrite(SS_arduino, HIGH); // 슬레이브가 선택되지 않은 상태
  digitalWrite(SS_EEPROM,HIGH); //적어도 되고 안적어도 되고
  
  SPI.begin();
  //안정적인 전송을 위해 분주비를 높여 전송속도를 낮춤
  SPI.setClockDriver(SPI_CLOCK_DIV16);
}

void loop() {
  const char* p ="Hello World\n";
  digitalWrite(SS_arduino, LOW); //Slave(53)선택
  for(int i=0; i<strlen(p); i++){
    SPI.transfer(p[i]); //byte단위로 slave에 데이터 전송
  }
  digitalWrite(SS_arduino,HIGH); //슬레이브 선택 해제
  delay(1000);
}
