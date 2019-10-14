#include <buttonClass.h>

#define BUTTON_PIN 7
#define LED_PIN 8

button myButton(BUTTON_PIN, LED_PIN);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  int newstate = myButton.getState();
  if (newstate != state) {
    state = newstate;
    if (state) {
      Serial.println("Button is on");
    } else {
    Serial.println("Button is off");
  }
  
  if (Serial.available() > 0) 
  {
    char c = Serial.read();
    switch c 
    {
      case '0':
        Serial.println("MENU");
        Serial.println("0: display this menu");
        Serial.println("1: set state to on");
        Serial.println("2: set state to off");
        Serial.println("3: get the current state");
        Serial.println("4: print the current number of actions");
        break;
      case '1':
        Serial.println("Setting state to on");
        myButton.setState(true);
        break;
      case '2':
        Serial.println("Setting state to off");
        mybutton.setState(false);
        break;
      case '3':
        Serial.print("Current state is: ");
        Serial.println(myButton.getState());
        break;
      case '4':
        Serial.print("Current number of actions is: ");
        Serial.println(myButton.getNumberOfActions);
        break;
    }
}
