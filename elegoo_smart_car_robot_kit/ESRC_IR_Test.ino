//IR remote control test with LED and also get the unique codes for the keys from the serial monitor

#include <IRremote.h>

#define IR_PIN 12         //define signal recieving pin
#define LED 13            //define LED pin

IRrecv irrecv(IR_PIN);    //initialization
decode_results result;   //define the structure type
bool state = LOW;        // define default input mode

void changeState() {
  //change the state of the LED
  state = !state;
  digitalWrite(LED,state);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      //serial monitor @ 9600 baud rate
  irrecv.enableIRIn();    //start recieving
  pinMode(LED,OUTPUT);   // initialize LED as output
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&result)) {
    Serial.println(result.value);
    irrecv.resume();    //receive the next value;
    delay(150);

    if(result.value) {
      changeState();
    }
  }
}
