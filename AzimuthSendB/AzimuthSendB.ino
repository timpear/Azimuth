/********************************************
Controller for Azimuth
Transmit via serial to receiver
using Trinket board and rotary encoder
connect pin 0 to RX and pin 1 to TX on XBee
********************************************/

#include <SoftwareSerial.h>
#define SerialPin 0
SoftwareSerial Serial(1,0);

int potPin = 3;
int c = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int val = map(analogRead(potPin), 0, 1010, 4, 0);
  c = c - val;
 
  if (c != 0) {
    Serial.print(val + 1);
 }
  
  c = val;
  delay(100);
}
