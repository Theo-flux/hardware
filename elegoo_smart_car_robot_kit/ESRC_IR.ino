// IR remote control for the robot

#include <IRremote.h>

#define IR_PIN 12         //define signal recieving pin
#define F 16736925       // define the code for the up key as gotten from the IR remote test earlier
#define B 16754775
#define L 16720605
#define R 16761405
#define S 16712445

#define ENA 5    //initialize pin 5 for motor A 
#define ENB 6    //initialize pin 6 for motor B 
#define IN1 7    //initialize pin 7 to control motor A  
#define IN2 8    //initialize pin 8 to control motor A 
#define IN3 9    //initialize pin 9 to control motor B 
#define IN4 11   //initialize pin 11 to control motor B 

IRrecv irrecv(IR_PIN);
decode_results result;
unsigned long val;
unsigned char carspeed = 125;
unsigned long premillis;

void forward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("forward");  
}

void backward() {
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("forward");  

}

void left() {
  analogWrite(ENA,carspeed);
  analogWrite(ENB,carspeed);  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("LEFT");  
}

void right() {
  analogWrite(ENA,carspeed);
  analogWrite(ENB,carspeed);  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("RIGHT"); 
}

void stop() {
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("STOP!");

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  stop();
  irrecv.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&result)) {
    premillis = millis();
    val = result.value;
    Serial.println(val);
    irrecv.resume();
    switch(val) {
      case F: forward(); break;
      case B: backward(); break;
      case L: left(); break;
      case R: right(); break;
      case S: stop(); break;
      default: break;
    }

  }
  else {
    if(millis() - premillis > 500) {
      stop();
      premillis = millis();
    }
  } 
}
