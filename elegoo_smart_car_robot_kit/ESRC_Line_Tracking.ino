#define M_LT !digitalRead(4)
#define L_LT !digitalRead(2)
#define R_LT !digitalRead(10)

#define ENA 5            //initialize pin 5 for motor A 
#define ENB 6           //initialize pin 6 for motor B 
#define IN1 7           //initialize pin 7 to control motor A  
#define IN2 8           //initialize pin 8 to control motor A 
#define IN3 9          //initialize pin 9 to control motor B 
#define IN4 11        //initialize pin 11 to control motor B 
#define carspeed 180

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M_LT,INPUT);
  pinMode(L_LT,INPUT);
  pinMode(R_LT,INPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(M_LT) {
    forward();
  }
  else if(L_LT) {
    left();
    while(L_LT);
  }
  else if(R_LT) {
    right();
    while(R_LT);
  }

}
