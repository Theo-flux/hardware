#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos = 0;pos <= 180; pos++){
    myservo.write(pos);
    delay(500);
  }

  for(pos = 180; pos>=0 ; pos--){
    myservo.write(pos);
    delay(500);
  }

}
