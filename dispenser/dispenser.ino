#include <Servo.h>

#define T 0
#define CLK 1
#define servopin 2
#define A 13

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  servo.attach(servopin);
  pinMode(T, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(A, INPUT);
  digitalWrite(T, 0);
  digitalWrite(CLK, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    int coin = Serial.parseInt();
    if(coin == 10){
      Serial.println("Dime");
      digitalWrite(CLK, 1);
      delay(1);
      digitalWrite(CLK, 0);
    }else if(coin == 25){
      Serial.println("Quarter");
      digitalWrite(T, 1);
      delay(1);
      digitalWrite(CLK, 1);
      delay(1);
      digitalWrite(T, 0);
      digitalWrite(CLK, 0);
    }
  }
  if(digitalRead(A) == 0){
    servo.write(0);
  }else{
    servo.write(90);
  }
}
