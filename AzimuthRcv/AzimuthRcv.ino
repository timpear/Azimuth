/******************************************  
Controller for Azimuth
Receive via serial and output as keyboard
Teensy 3.1 or other, USB type KEYBOARD
******************************************/

char data;
const int BUTTON = 14;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup() {
  Serial1.begin(9600);
  pinMode(BUTTON, INPUT);
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

void loop() {
  while (Serial1.available() > 0){
    data = Serial1.read();
    Keyboard.print(data);
  }
  
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    Keyboard.print("q");
  }
  lastButton = currentButton;
}
