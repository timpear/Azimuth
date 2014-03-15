/******************************************  
Controller for Azimuth
Transmit via serial to receiver
using Teensy 3.0 board and rotary encoder
powered on with Sparkfun Wake on Shake

note -- this encoder has a glitch which jumps up in number frequently,
so the encoder pins were switched and output message reversed.
The problem now happens when winding up, which is OK in this application.
******************************************/

#include <Encoder.h>
Encoder myEnc(3, 4);
const int ledPin = 13;
const int wakePin = 12;
unsigned long currentMillis = 0;
unsigned long prevMillis = 0;
long wakeTime = 900000; // on for 15 minutes

void setup() {
//  Serial.begin(9600);
  Serial1.begin(9600);

// unused pins on Teensy set to OUTPUT to save power
// used pins: 0, 1, 3, 4, 12, 13
  pinMode(2, OUTPUT);
  for (int i=5; i < 24; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(ledPin, OUTPUT);
  pinMode(wakePin, OUTPUT);
  digitalWrite(wakePin, HIGH);
  currentMillis = millis();
  prevMillis = currentMillis;
}

long oldPosition  = -999;

void loop() {
  currentMillis = millis();
  long newPosition = myEnc.read();
  if (newPosition > (oldPosition + 15)){
//    Serial.print("<");
    Serial1.print("<");
    prevMillis = currentMillis;
//    digitalWrite(ledPin, HIGH); //just for blinky
    oldPosition = newPosition;
    delay(10);
//    digitalWrite(ledPin, LOW); //just for blinky
  }
  else if (newPosition < (oldPosition - 15)){
//    Serial.print(">");
    Serial1.print(">");
      prevMillis = currentMillis;
//    digitalWrite(ledPin, HIGH); //just for blinky
    oldPosition = newPosition;
    delay(10);
//    digitalWrite(ledPin, LOW); //just for blinky
  }

    if (currentMillis - prevMillis > wakeTime) {
    digitalWrite(wakePin, LOW); // Wake-On-Shake OK to turn off
  }  
}
