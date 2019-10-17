#include <buttonClass.h>

button domeButtons[] = {button(22,23),button(24,25),button(26,27),button(28,29),button(30,31),button(32,33),button(34,35),button(36,37),button(38,39)};

void setup() {
  
}

void loop() {
  for(int i = 0; i < sizeof(domeButtons)/sizeof(domeButtons[0]); i++){
    domeButtons[i].getState();
  }
  delay(20);
}
