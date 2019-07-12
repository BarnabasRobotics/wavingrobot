#include <Servo.h>

Servo hand;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,INPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  hand.attach(9);
  hand.write(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(12));

  if(digitalRead(12)) {
      digitalWrite(6,HIGH);
      for (int i=0;i<3;i++) {
        hand.write(80);
        delay(100);
        hand.write(130);
        delay(100);
      }
      hand.write(100);
      // wait for the hand to settle down before polling again
      // without the delay, you may get a false trigger
      delay(1000);
      digitalWrite(6,LOW);
      
  }
  

}
