//Bluetooth test with LED

#define LED 13   // define LED as pin 13

bool state = LOW;
char getstr;
unsigned char carspeed = 125;

void changeState() {
  state = !state;
  digitalWrite(LED, state);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      
  pinMode(LED,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  getstr = Serial.read();
  if(getstr == 'a') {
    changeState();
  }
  
}
