void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);  //declare pin 3(green led) as output
  pinMode(11,OUTPUT); //declare pin 11(yellow led) as output
  pinMode(6,OUTPUT);  //declare pin 6(red led) as output
  pinMode(5,INPUT);   //declare pin 5(push button) as input
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(5) == LOW){
    digitalWrite(11,HIGH);    //turn green led on
    digitalWrite(6,LOW);      //turn yellow led off
    digitalWrite(3,LOW);      //turn red led off
    delay(3000);              //wait for 3secs
  
    digitalWrite(11,LOW);    //turn green led off
    digitalWrite(6,HIGH);    //turn yellow led on
    digitalWrite(3,LOW);    //turn red led off
    delay(3000);            //wait for 3secs
    
    digitalWrite(11,LOW);   //turn green led off
    digitalWrite(6,LOW);    //turn yellow led off
    digitalWrite(3,HIGH);   //turn red led on
    delay(3000);            //wait for 3secs
  }

  if(digitalRead(5) = HIGH){
    digitalWrite(11,HIGH);    //turn green led on
    digitalWrite(6,LOW);      //turn yellow led off
    digitalWrite(3,LOW);      //turn red led off
    delay(1000);              //wait for 1sec

    digitalWrite(11,LOW);    //turn green led off
  }

}
