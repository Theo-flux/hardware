#define green 11
#define yellow 10
#define red 9
#define potPin A0

int potRead = 0;
int potWrite = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  //pinMode(potPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potRead = analogRead(potPin);
  potWrite = potRead/4;

  analogWrite(green,potWrite);
  analogWrite(yellow,potWrite);
  analogWrite(red,potWrite);

  /*if(potRead > 1000){
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    delay(1000);
    digitalWrite(green,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,HIGH);
  }else {
    analogWrite(green,potWrite);
    analogWrite(yellow,potWrite);
    analogWrite(red,potWrite);
  }*/

  // Turn on each lead as the value reaches 0, 127 and 255.
  if(potRead < 200){
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
  }else if((potRead >200) && (potRead <=510)){
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,HIGH);
  }else {
    digitalWrite(green,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,HIGH);
  }
  
  Serial.print(potRead);
  Serial.print(":");
  Serial.println(potWrite);
}
