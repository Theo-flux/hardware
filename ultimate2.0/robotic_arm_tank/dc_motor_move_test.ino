#include <MeMegaPi.h>
#include <Wire.h>

MeMegaPiDCMotor back_motor1(PORT1A);
MeMegaPiDCMotor back_motor2(PORT1B);

MeMegaPiDCMotor front_motor1(PORT2A);
MeMegaPiDCMotor front_motor2(PORT2B);

MeMegaPiDCMotor motor(PORT3A);

uint8_t tankSpeed = 150;
//float cranespeed = 150.0;
//
//
//void down(){
//  crane1.move(-1080,cranespeed);
//  crane2.move(-1080,cranespeed);
//}
//
//void up(){
//  crane1.move(1080,cranespeed);
//  crane2.move(1080,cranespeed);
//}

void runforward(){
  back_motor1.run(-tankSpeed);
  back_motor2.run(-tankSpeed);
  front_motor1.run(tankSpeed);
  front_motor2.run(tankSpeed);
}

void runbackward(){
  back_motor1.run(tankSpeed);
  back_motor2.run(tankSpeed);
  front_motor1.run(-tankSpeed);
  front_motor2.run(-tankSpeed);
}

void closegripper(){
  motor.run(tankSpeed);
}

void opengripper(){
  motor.run(-tankSpeed);
}

void Stop(){
  back_motor1.stop();
  back_motor2.stop();
  front_motor1.stop();
  front_motor2.stop();
  motor.stop();
}

void setup() {
  // put your setup code here, to run once:
  Stop();

}

void loop() {
  // put your main code here, to run repeatedly:
//  runforward();
//  delay(3000);
//  runbackward();
//  delay(5000);
  opengripper();
//  delay(1000);
//  closegripper();
  Stop();
//  delay(5000);
}
