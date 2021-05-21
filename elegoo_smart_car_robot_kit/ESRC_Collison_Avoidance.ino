#include <Servo.h>

Servo myservo;

#define ENA 5            //initialize pin 5 for motor A 
#define ENB 6           //initialize pin 6 for motor B 
#define IN1 7           //initialize pin 7 to control motor A  
#define IN2 8           //initialize pin 8 to control motor A 
#define IN3 9          //initialize pin 9 to control motor B 
#define IN4 11        //initialize pin 11 to control motor B 
#define carspeed 180

int echo = A4;
int trig = A5;
int r_dist = 0 ,l_dist = 0, m_dist = 0;
int min_dist = 100;

void forward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  //Serial.println("forward");  
}

void backward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  //Serial.println("forward");  

}

void left() {
  analogWrite(ENA,carspeed);
  analogWrite(ENB,carspeed);  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  //Serial.println("LEFT");  
}

void right() {
  analogWrite(ENA,carspeed);
  analogWrite(ENB,carspeed);  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  //Serial.println("RIGHT"); 
}

void stop() {
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  //Serial.println("STOP!");
}

int Distance_test(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float dist = pulseIn(echo,HIGH); 
  dist = dist / 58;
  return (int)dist;
}

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(90);
  delay(500);
  m_dist = Distance_test();

  if(m_dist <= min_dist){
    stop();
    delay(500);
    myservo.write(0);
    delay(1000);
    r_dist = Distance_test();
    delay(500);
    
    myservo.write(180);
    delay(1000);
    l_dist = Distance_test();
    delay(500);
    myservo.write(90);
    delay(1000);

    if(r_dist > l_dist){
      right();
      delay(360);
    }else if(r_dist < l_dist){
      left();
      delay(360);
    }else if(r_dist <= min_dist or l_dist <= min_dist){
      backward();
      delay(180);
    }
    else {
      forward();
    }
    
  }
  else {
    forward();
  }
}
