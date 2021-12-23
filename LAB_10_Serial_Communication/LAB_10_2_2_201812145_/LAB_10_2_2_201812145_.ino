//SPI통신 - 슬레이브에서 마스터로부터 수신된 데이터 출력
//SPI라이브러리는 Slave 모드를 지원하지 않음
//SPCR(SPI Control Register)를 직접 조작해야함
#include<SPI>
char buf[100];
//pos와 process_it은 인터럽트 처리 루틴에서 값을 바꾸는 변수이므로
//volatile 선언을 통해 매번 값을 참조하도록 설정해야 한다
volatile byte pos = 0 ;
volatile boolean process_it = false


void setup() {
  Serial.begin(9600);
  //MOSI,SCLK,SS는 입력으로 설정하지 않아도 된다. 왜냐하면 하드웨어만으로 통신하기 때문에
  //MISO역시 이 예에서는 사용하지 않으므로 생략할 수 있다.
  pinMode(MISO,OUTPUT);
  pinMode(MOSI,INPUT);
  pinMode(SCK,INPUT);
  pinMode(SS,INPUT);
  //마스터의 전송 속도에 맞추어 통신 속도를 설정
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  //SPI 통신을 위한 레지스터 설정
  //SPCR : SPI Control Register
  //SPCR에서 SPIE - 비트 7번, SPE - 비트 6번, MSTR - 비트 3번
  //SPE, MSTR, SPIE - 매크로 값
  
  SPCR |= (1 << SPE);   //SPE : 1 - SPI통신을 사용 할 수 있도록 설정
  SPCR &= ~(1 << MSTR);  //MSTR : 0 - 슬레이브로 동작하도록 설정
  SPCR |= (1 << SPIE)   //SPIE : 1 - 데이터가 수신된 경우, Interrupt가 발생하도록 설정
}

//SPI Interrupt
ISR(SPI_STC_vect){
  byte c = SPDR; //마스터에서 transfer로 보낸 값
  if(pos< sizeof(buf)){
    buf[pos++] = c;
    if(c =='\n'){
      process_it = true;
    }
  }
}

void loop() {
  if(process_it){
    buf[pos] = 0;
    Serial.print(buf);
    pos = 0;
    process_it = false;
  }
}
