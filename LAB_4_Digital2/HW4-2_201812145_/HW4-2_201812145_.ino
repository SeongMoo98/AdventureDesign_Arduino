/*
 * HW4-2_201812145
 * 버튼을 통한 LED 점멸순서 변경
 * 1->2->3->4->1 ...
 * 버튼을 누르면 4->3->2->1->4...
 */
int pins_LED[] = {2, 3, 4, 5};
//14번에 풀다운 저항
int pins_button = 14;

//불이 켜지는 LED결정
int LED_Patterns[]={0b0001, 0b0010, 0b0100, 0b1000};

//버튼을 누르면 true, 안누르면 false
boolean state_previous = false;

//state = 0 이면 1->2->3->4->1 ...
//state = 1 이면 4->3->2->1->4 ... 
//index는 LED배열 index
int state = 0, index=0;

void setup() {
  Serial.begin(9600);
  pinMode(pins_button, INPUT);
  
  for(index=0; index<4; index++){
    pinMode(pins_LED[index], OUTPUT);
  }
}

void loop() {
  boolean state_current = digitalRead(pins_button);

  if(state==0){
    if((state_current==true) && (state_previous==false)){
      index-=2; 
      state_previous=true;
      state=1;
    }
    else{
      if((state_current==false) && (state_previous==true)){
        state_previous=false;
      }
      if(index==4){
        index=0;
      }
      
      if(index<4){
        for(int i=0; i<4; i++){
          digitalWrite(pins_LED[i],bitRead(LED_Patterns[index],i));
        }
        index++;
        delay(500);
      }
    }
  }

  if(state ==1){
    if((state_current==true) && (state_previous==false)){
      index+=2; 
      state_previous=true;
      state=0;
    }
    else{
      if((state_current==false) && (state_previous==true)){
        state_previous=false;
      }
      if(index==-1){
        index=3;
      }
      if(index>=0){
        for(int i=0; i<4; i++){
          digitalWrite(pins_LED[i],bitRead(LED_Patterns[index],i));
        }
        index--;
        delay(500);
      }
    }
  }
 
}
