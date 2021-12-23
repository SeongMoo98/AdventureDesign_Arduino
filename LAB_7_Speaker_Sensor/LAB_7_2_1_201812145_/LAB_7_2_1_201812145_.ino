//센서 - 온도센서, 조도센서 - PWM신호 이용 ==> analogRead()
//ADC를 통해 디지털 변환 과정이 필요하다
void setup( ) {
  Serial.begin(9600); // 직렬 포트 초기화
}
void readTemperature() {
  // 온도 센서 읽기
  int reading = analogRead(55); 
  // ADC 반환값을 전압으로 변환 - 기준전압(5V)
  float voltage = reading * 5.0 / 1024.0;
  Serial.print (voltage);
  Serial.print (" V : ");
  // 전압에 100을 곱하면 섭씨 온도를 얻을 수 있다.
  float temp_C = voltage * 100;
  Serial.print (temp_C);
  Serial.print (" C, ");
  
  // 화씨 온도로 변환
  float temp_F = (temp_C * 9.0/5.0)+32;
  Serial.print (temp_F);
  Serial.println(" F");
}

//어두운 곳에서 저항이 커진다 ==> V가 커진다
void readIlluminance() {
  // 조도 센서 읽기
  int reading = analogRead(56); 
  Serial.print("ADC : ");
  Serial.print(reading);
  // ADC 반환 값을 전압으로 변환
  float voltage = reading * 5.0 / 1024.0;
  Serial.print(", Voltage : ");
  Serial.println(voltage);
}

void loop( ) {
  readTemperature();
  readIlluminance();
  delay(1000);
}
