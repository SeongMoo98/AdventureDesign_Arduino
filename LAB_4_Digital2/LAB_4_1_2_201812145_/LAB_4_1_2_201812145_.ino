void setup() {
  Serial.begin(9600);

}

void loop() {
  //정렬한 문자열 배열
  String str[5] = {"abc", "ABC", "!@#", "라라라", "123"};
  
  //문자열 정렬
  for(int i = 0; i < 4; i++){
    for(int j = i+1; j < 5; j++){
      int compare = str[i].compareTo(str[j]);
      //오름차순 정렬, 내림차순 정렬은 compare < 0
      if(compare>0){
        String temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  
  //정렬된 문자열 출력
  for(int i = 0; i < 5; i++){
    Serial.println(String(i) + " : " + str[i]);
  }
  while(true);

//  //str2 출력
//  String str2[7] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
//  //문자열 내림차순 정렬
//  for(int i = 0; i < 6; i++){
//    for(int j = i+1; j < 7; j++){
//      int compare = str2[i].compareTo(str2[j]);
//      if(compare < 0){
//        String temp = str2[i];
//        str2[i] = str2[j];
//        str2[j] = temp;
//      }
//    }
//  }
//  
//  //정렬된 문자열 출력
//  for(int i = 0; i < 7; i++){
//    Serial.println(String(i) + " : " + str2[i]);
//  }
//  while(true);


}
