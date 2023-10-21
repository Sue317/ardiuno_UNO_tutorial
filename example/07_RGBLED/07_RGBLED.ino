byte R = 9;   // 定義 R 腳位為 9
byte G = 10;  // 定義 G 腳位為 10
byte B = 11;  // 定義 B 腳位為 11

void setup() {
  pinMode(R,OUTPUT);  // 設定 R, G, B 三個腳位皆作為輸出
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
}

void loop() {
  analogWrite(R,0);  // 數字從 0 ~ 255, 8 bits
  analogWrite(G,134);
  analogWrite(B,139);
  delay(1000);
  analogWrite(R,70);
  analogWrite(G,130);
  analogWrite(B,180);
  delay(1000);
}

