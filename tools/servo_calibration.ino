
#include <Servo.h>

Servo myServo;

const int potPin = A0;

int lastPotValue;
int currentPotValue;

void setup() {
  myServo.attach(9);

  Serial.begin(9600);

  int initValue = analogRead(potPin);
  lastPotValue = initValue + 5;
  currentPotValue = initValue;
}

void loop() {
  currentPotValue = analogRead(potPin);

  if( abs(currentPotValue - lastPotValue) > 4 )
  {
    lastPotValue = currentPotValue;
    int angle = map(currentPotValue, 0, 1023, 0, 180);
    myServo.write(angle);

    Serial.print("pot value: ");
    Serial.print(currentPotValue);
    Serial.print("  angle: ");
    Serial.println(angle);
  }
  
  delay(15);
}
