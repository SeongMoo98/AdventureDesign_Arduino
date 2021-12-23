/*
 * HW2_201812145 
 * Serial 입력으로 두 정수를 입력받아 합을 출력
 */
//HW2_201812145

int nState=1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(nState){
    Serial.println("Enter 2 Integer to add");
    nState=0;
  }
  
  //입력대기 - 입력이 없으면 0 반환
  //parseInt로 정수를 받음
  while(Serial.available()==0){
    }
  int num1=Serial.parseInt();
  

  while(Serial.available()==0){
    }
  int num2=Serial.parseInt();
  
  int sum=num1+num2;
  
  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(sum);

  nState=1;
}
