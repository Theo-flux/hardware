#include <Servo.h>

Servo myServo;

const int pot = A0; //potentiometer pin
int potValue = 0;
int servoAngle = 0;
const int btn = 8;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(11);
  Serial.begin(9600);
  pinMode(btn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn)==HIGH){
    myServo.write(179);
  }else{
    potValue = analogRead(pot);
    servoAngle = map(potValue,0,1023,0,179);
    myServo.write(servoAngle);
    Serial.print(potValue);
    Serial.print(":");
    Serial.println(servoAngle);
    delay(100); 
  }
}
