#include <buttonClass.h>

#define BUTTON_PIN 7

button myButton(BUTTON_PIN);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

int state = 0;
int n_press = 0;
int n_release = 0;

void loop() {
  // put your main code here, to run repeatedly:
 
  int newstate = myButton.getState();
  if (newstate != state) {
    state = newstate;
    if (state) {
      n_press++;
    } else {
      n_release++;
    }
    Serial.print("Press: ");
    Serial.print(n_press);
    Serial.print("  Release: ");
    Serial.println(n_release);
  }
  
}
