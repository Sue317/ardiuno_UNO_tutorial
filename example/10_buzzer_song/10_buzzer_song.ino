float BPM = 200.0;                // Beats Per minute
int quarter = (60/BPM)*1000;      // 四分音符
int half = quarter * 2;           // 半分音符
int eigth = quarter / 2;          // 八分音符
int size;

int beats[] = {
  quarter, quarter, eigth, eigth, quarter,
quarter, quarter, eigth, eigth, quarter,
quarter, eigth, eigth, quarter, eigth, eigth, 
eigth, eigth, eigth, eigth, eigth, eigth, eigth, eigth,

};

void setup() {
  pinMode(2,OUTPUT);  // 設定腳位 2 為輸出
  size = sizeof(beats) / sizeof(beats[0]);  // 計算儲存整首歌陣列的大小
  digitalWrite(2,LOW);
  delay(1000);
}

void loop() {

  for (int i = 0; i < size; i++) {
    digitalWrite(2,HIGH); // 輸出高電位，會叫
    delay(beats[i]);
    digitalWrite(2,LOW);
    delay(beats[i]);
  }
  // digitalWrite(2,HIGH); // 輸出高電位，會叫
  // delay(1000);
  // digitalWrite(2,LOW);  // 輸出低電位，不會叫
  // delay(1000);
}
