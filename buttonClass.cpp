#include "buttonClass.h"
#include "arduino.h"

button::button(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  m_pin = pin;
  m_state = 0;
  m_timeOfAction = 0;
}

int button::getState()
{
  int val = digitalRead(m_pin);
  unsigned long currentTime = millis();
  unsigned long timeSinceAction = currentTime-m_timeOfAction;
  if (timeSinceAction > 100) {
    if (val != m_state) {
      m_timeOfAction = currentTime;
      m_state = val;
    }
  }
  return m_state;
}
