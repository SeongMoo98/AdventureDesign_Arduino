/*
 * HW3_201812145
 * LED의 패턴 출력 1000 -> 1100 -> 1110 -> 1111 -> 1110 ....
 */

int pins[] = {2,3,4,5}; 
int pattern,shift;

void setup() {
  Serial.begin(9600);             
  for(int i = 0; i < 4; i++){     
    pinMode(pins[i],OUTPUT);      //OUTPUT 모드로 설정
    digitalWrite(pins[i],LOW);    //꺼진 상태로 시작
  }
}

void loop() {
  //shift-0,1,2,3,2,1 ==> 6개  - 패턴 6번이 1개의 루프이다
  for(int index = 0; index <6; index++){
    pattern=1;
    if(index<4){
      shift=index;
    }
    else{
      shift=6-index;
    }

    
    for(int i=0; i<shift;i++){
      pattern=(pattern<<1) | 0x01;
    }
    
    if(pattern==0b0001){
      digitalWrite(pins[0],HIGH);
      digitalWrite(pins[1],LOW);
      digitalWrite(pins[2],LOW);
      digitalWrite(pins[3],LOW);
    }
    else if(pattern==0b0011){
      digitalWrite(pins[0],HIGH);
      digitalWrite(pins[1],HIGH);
      digitalWrite(pins[2],LOW);
      digitalWrite(pins[3],LOW);
    }
    else if(pattern==0b0111){
      digitalWrite(pins[0],HIGH);
      digitalWrite(pins[1],HIGH);
      digitalWrite(pins[2],HIGH);
      digitalWrite(pins[3],LOW);
    }
    else if(pattern==0b1111){
      digitalWrite(pins[0],HIGH);
      digitalWrite(pins[1],HIGH);
      digitalWrite(pins[2],HIGH);
      digitalWrite(pins[3],HIGH);
    }
  delay(1000);        
  } 
  
}
