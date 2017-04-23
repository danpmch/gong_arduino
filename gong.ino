
#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int firePin = 12;

const int STRIKE_ANGLE = 80;
const int MAX_START_ANGLE = 0;
const int TRAVEL_TIME = 120;

int lastPotValue;
int currentPotValue;
int currentMaxAngle;

void setup() {
  myServo.attach(9);
  myServo.write(MAX_START_ANGLE);

  Serial.begin(9600);

  int initValue = analogRead(potPin);
  lastPotValue = initValue + 5;
  currentPotValue = initValue;

  pinMode(firePin, INPUT);
}

void fire()
{
  myServo.write(STRIKE_ANGLE);
  delay(TRAVEL_TIME);
  myServo.write(currentMaxAngle);
  delay(TRAVEL_TIME);
}

void loop() {
  currentPotValue = analogRead(potPin);

  if( abs(currentPotValue - lastPotValue) > 4 )
  {
    lastPotValue = currentPotValue;
    currentMaxAngle = map(currentPotValue, 0, 1023, STRIKE_ANGLE, MAX_START_ANGLE);
    myServo.write(currentMaxAngle);
  }

  delay(15);

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
