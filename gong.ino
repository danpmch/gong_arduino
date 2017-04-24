
#include <Servo.h>

Servo myServo;

const int firePin = 12;

const int STRIKE_ANGLE = 80;
const int MAX_START_ANGLE = 0;
const int TRAVEL_TIME = 120;

void setup() {
  myServo.attach(9);
  myServo.write(MAX_START_ANGLE);

  Serial.begin(9600);

  pinMode(firePin, INPUT);
}

void fire()
{
  myServo.write(STRIKE_ANGLE);
  delay(TRAVEL_TIME);
  myServo.write(MAX_START_ANGLE);
  delay(TRAVEL_TIME);
}

void loop() {

  if(Serial.available())
  {
     Serial.read();
     Serial.flush();
     fire();
  }

  
  if( digitalRead(firePin) )
  {
    fire();
  }
  
  delay(15);
}
