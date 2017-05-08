
#include <Servo.h>

const int firePin = 12;
const int solenoidPin = 9;

const int ON_DURATION = 25;

void setup() {
  Serial.begin(9600);

  pinMode(firePin, INPUT);

  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, LOW);
}

void fire()
{
  digitalWrite(solenoidPin, HIGH);
  delay(ON_DURATION);
  digitalWrite(solenoidPin, LOW);
}

void loop() {

  if(Serial.available())
  {
     Serial.read();
     Serial.flush();
     fire();
  } else if( digitalRead(firePin) ) {
    fire();
  }  

  delay(15);
}
