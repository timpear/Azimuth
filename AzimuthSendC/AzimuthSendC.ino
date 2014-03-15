/********************************************
Controller for Azimuth
Transmit via serial to receiver
using Trinket board and button
connect pin 0 to RX and pin 1 to TX on XBee
********************************************/

#include <SoftwareSerial.h>
#define SerialPin 0
SoftwareSerial Serial(1,0);

const int BUTTON = 4;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup(){
  Serial.begin(9600);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop(){
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    Serial.print("z");
  }
  
  lastButton = currentButton;
  
}
