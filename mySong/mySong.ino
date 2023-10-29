#include "notes.h"       // 引入函式庫

int buzzerPin = 9;        // 定義蜂鳴器引腳
int size;
float BPM = 124.0;                // Beats Per minute
int quarter = (60/BPM)*1000;      // 四分音符
int half = quarter * 2;           // 半分音符
int eigth = quarter / 2;          // 八分音符
int sixteen = quarter / 4;


// 簡譜對照表
// 1: C4, 2: D4, 3: E4, 4: F4, 5: G4, 6: A4
// 5. : G3


int melody[] = { 
  NOTE_C4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_C4, NOTE_D4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,  NOTE_E4, NOTE_C4, NOTE_B4, NOTE_B4, NOTE_B4, 0,
  NOTE_C4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_C4,  
  NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_A5, NOTE_G6, NOTE_G6, NOTE_A7, NOTE_D7, 
  //NOTE_E6, 
  //NOTE_D3, NOTE_C3, 

};

int noteDurations[] = {
  eigth, eigth, eigth, eigth, eigth, eigth, eigth, eigth,
  eigth, eigth, sixteen, sixteen, sixteen, sixteen, eigth, eigth, sixteen, sixteen, sixteen, sixteen, 
  eigth, eigth, eigth, eigth, eigth, eigth, eigth, eigth,
  eigth, eigth, eigth, eigth, sixteen, sixteen, sixteen, sixteen, sixteen, sixteen, sixteen, sixteen,
  //eigth, 
  //sixteen, sixteen, 

};

void setup() {
  pinMode(buzzerPin, OUTPUT);                 // 設置蜂鳴器腳位為輸出
  Serial.begin(9600);
  size = sizeof(melody) / sizeof(melody[0]);  // 計算儲存整首歌陣列的大小
  delay(1000);
}

void loop() {
  // 播放音樂
  for (int i = 0; i < size; i++) {
    int duration = noteDurations[i];
    tone(buzzerPin, melody[i], duration);
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
  delay(10);  // 停頓一秒
}

