const int leftledPin = 9;   // 左LEDが接続されているピン番号
const int rightledPin = 10;  // 右LEDが接続されているピン番号

void setup() {
  pinMode(leftledPin, OUTPUT);  // 左LEDピンを出力として設定
  pinMode(rightledPin, OUTPUT); // 右LEDピンを出力として設定
}

void loop() {
  goesOutForAMoment();
}

void goesOutForAMoment() {
  // 左のLEDを徐々に明るくし、右のLEDを徐々に暗くする
  for (int Lbrightness = 0, Rbrightness = 255; Lbrightness <= 255; Lbrightness++, Rbrightness--) {
    analogWrite(leftledPin, Lbrightness);
    analogWrite(rightledPin, Rbrightness);
    delay(20); // 明るさの変更速度を調整
  }
  delay(1000);

  // 左のLEDを徐々に暗くし、右のLEDを徐々に明るくする
  for (int Lbrightness = 255, Rbrightness = 0; Lbrightness >= 0; Lbrightness--, Rbrightness++) {
    analogWrite(leftledPin, Lbrightness);
    analogWrite(rightledPin, Rbrightness);
    delay(20); // 明るさの変更速度を調整
  }
  delay(1000);
}

void onlyOne() {
  // 左のLEDを点灯し、右のLEDを消灯
  for (int Lbrightness = 0; Lbrightness <= 255; Lbrightness++) {
    analogWrite(leftledPin, Lbrightness);
    delay(20); // 明るさの変更速度を調整
  }

  delay(100);
  for (int Lbrightness = 255; Lbrightness >= 0; Lbrightness--) {
    analogWrite(leftledPin, Lbrightness);
    delay(20); // 明るさの変更速度を調整
  }
delay(100);
  // 右のLEDを消灯し、右のLEDを点灯
  for (int Rbrightness = 0; Rbrightness <= 255; Rbrightness++) {
    analogWrite(rightledPin, Rbrightness);
    delay(20); // 明るさの変更速度を調整
  }
  delay(100);
  for (int Rbrightness = 255; Rbrightness >= 0; Rbrightness--) {
    analogWrite(rightledPin, Rbrightness);
    delay(20); // 明るさの変更速度を調整
  }
}
