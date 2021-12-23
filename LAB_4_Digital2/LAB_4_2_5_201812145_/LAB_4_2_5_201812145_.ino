//버튼 누른 횟수 세기 - 디바운싱
int pin_button = 15;
//버튼의 이전 상태
boolean state_previous = false;
//버튼의 현재 상태
boolean state_current;
//버튼을 누른 횟수
int count;

void setup() {
  Serial.begin(9600);
  pinMode(pin_button, INPUT);

}

void loop() {
  //버튼 상태 읽기
  state_current = digitalRead(pin_button);
  
  //버튼을 누른경우
  if(state_current){
    //이전 상태와 비교
    if(state_previous == false){
      count++;
      state_previous = true;
      Serial.println(count);
    }
    delay(50) //디바운싱
  }
  else{
    state_previous = false; 
  }
}
