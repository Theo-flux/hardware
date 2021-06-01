void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
  delay(3000);

  
  digitalWrite(11,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(3,LOW);
  delay(3000);
  
  digitalWrite(11,LOW);
  digitalWrite(6,LOW);
  digitalWrite(3,HIGH);
  delay(3000);
}
