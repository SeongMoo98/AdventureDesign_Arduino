/*HW7-1_201812145_이성무
 * 조도센서의 광량에 따라 LED가 켜지는 개수를 다르게 하는 프로그램
 * 어두우면 4개, 밝으면 모두 꺼지게함
 */
 
int pin_Ill = 56;
int pins_LED[] = {2,3,4,5};
int interval = (1023-(150+1)) / 4 ; 
int off_value = 150;

void setup() {
  for(int i=0; i<4; i++){
    pinMode(pins_LED[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int reading=analogRead(pin_Ill);
  Serial.print("ADC : ");
  Serial.print(reading);
  Serial.println();
  
  int num;
  if( reading <= off_value){
    num = 0; 
  }
  else{
    num = ((reading-off_value) / interval) + 1;
  }
  
  for(int i=0; i<4; i++){
    if( num > i ){
      digitalWrite(pins_LED[i],HIGH);
    }
    else{
      digitalWrite(pins_LED[i],LOW);
    }
  }
  delay(500);
}
