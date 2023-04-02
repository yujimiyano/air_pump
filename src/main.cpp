#include <Arduino.h>
#include <Easing.h>

EasingFunc<Ease::Cubic> e;
float start_sec;
float duration = 0.8;
float scale = 255.;

#define AIN 1
#define M1_A 5
#define M1_B 9
#define M2_A 6 
#define M2_B 10
#define SOL 11


#define PERIOD_LONG 1.5
#define PERIOD_SHORT 0.9

int val = 0;
int out = 0;


void setup() {
  Serial.begin(9600);
  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);
  pinMode(SOL, OUTPUT);

  e.duration(duration); // default duration is 1.0
  e.scale(scale); // default scale is 1.0

  start_sec = millis() / 1000.;

  // analogWrite(M1_A, 255);
  // analogWrite(M1_B, 0);
  // analogWrite(M2_A, 255);
  // analogWrite(M2_B, 0);

}

void loop() {

  // float now = millis() / 1000.;

  // float value = e.get(now - start_sec);

  // Serial.println(value);
  digitalWrite(SOL, HIGH);
  delay(100);
  analogWrite(M1_A, 255);
  analogWrite(M1_B, 0);
  analogWrite(M2_A, 0);
  analogWrite(M2_B, 0);

  delay(4000);

  digitalWrite(SOL, LOW);
  delay(100);
  analogWrite(M1_A, 0);
  analogWrite(M1_B, 0);
  analogWrite(M2_A, 255);
  analogWrite(M2_B, 0);

  delay(4000);


  // if(value > 255)
  // {
  //   start_sec = millis() / 1000.;
  //   if(duration == PERIOD_LONG) duration = PERIOD_SHORT;
  //   else if(duration == PERIOD_SHORT) duration = PERIOD_LONG;
  //   e.duration(duration); // default duration is 1.0
  //   Serial.println(duration);
  // }
  // delay(50);
  
}