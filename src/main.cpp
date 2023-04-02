#include <Arduino.h>

// 各種調整用の変数設定
#define IN_TIME 4000  // 空気を入れる時間
#define IN_DELAY 100  // 空気を入れるモータが動き始めるまでの時間
#define IN_POWER 255  // 空気を入れるモータの強さ(0~255)

#define OUT_TIME 4000 // 空気を抜く時間
#define OUT_DELAY 100  // 空気を抜くモータが動き始めるまでの時間
#define OUT_POWER 255 // 空気を抜くモータの強さ(0~255)

// モータドライバL9110Sのピン設定
#define M1_A 5  // 空気を入れるモータのピン設定A
#define M1_B 9  // 空気を入れるモータのピン設定B
#define M2_A 6  // 空気を抜くモータのピン設定A
#define M2_B 10 // 空気を抜くモータのピン設定B

// ソレノイド駆動用MOS-FETピン設定
#define SOL 11

void inflate(); // 空気を入れる関数の宣言
void deflate(); // 空気を抜く関数の宣言

void setup() {
  Serial.begin(9600);

  // モータ用のピンを出力に設定
  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);

  // ソレノイド用のピンを出力に設定
  pinMode(SOL, OUTPUT);
}

void loop() {
  inflate();
  deflate();
}

// 空気を入れる関数
void inflate(){
  digitalWrite(SOL, HIGH);  // ソレノイド駆動して、空気を入れるモータを風船に接続
  delay(IN_DELAY);               // ソレノイドの駆動を待つ時間(要らないかも)

  analogWrite(M1_A, IN_POWER);  // 空気を入れるモータを正転させる
  analogWrite(M1_B, 0);   　    // 空気を入れるモータを正転させる
  analogWrite(M2_A, 0);   　    // 空気を抜くモータを停止させる
  analogWrite(M2_B, 0);　       // 空気を抜くモータを停止させる
  delay(IN_TIME);               // 空気を入れる時間
}

// 空気を抜く関数
void deflate(){
  digitalWrite(SOL, LOW);  // ソレノイド駆動して、空気を抜くモータを風船に接続
  delay(OUT_DELAY);              // ソレノイドの駆動を待つ時間(要らないかも)

  analogWrite(M1_A, 0);           // 空気を入れるモータを停止させる
  analogWrite(M1_B, 0);           // 空気を入れるモータを停止させる
  analogWrite(M2_A, OUT_POWER);   // 空気を抜くモータを正転させる
  analogWrite(M2_B, 0);           // 空気を抜くモータを正転させる
  delay(OUT_TIME);                // 空気を抜く時間
}