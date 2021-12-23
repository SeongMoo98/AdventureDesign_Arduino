/*
 * HW4-1_201812145
 * Serial Momonitor에서 5개의 단어를 입력받고 오름차순 청렬
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int state = 1, index=0;
  char buffer[128];
  String str[5];
  
  while(index<5){
    if(state == 1){
      Serial.print("Enter the ");
      Serial.print(index+1);
      Serial.print("th Word -->");
      state = 2;
    }

    while(Serial.available()){
      int len = Serial.readBytesUntil('\n', buffer, 127);
      if(len > 0){
        buffer[len] = '\0';
        str[index++] = String(buffer);
        Serial.println(str[index]);
        state = 1;
        break;
      }
    }
  }

  for(int i=0; i<4; i++){
    for(int j=i+1; j<5; j++){
      int compare = str[i].compareTo(str[j]);
      if(compare>0){ //오름차순 정렬
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }

  Serial.println("After Sorting");
  for(int k=0;k<5;k++){
    Serial.println(str[k]);
  }
    

}
