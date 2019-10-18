#include "buttonClass.h"
#include "arduino.h"

button::button(int buttonPin, int ledPin, int numStates) {

    // Set the pin modes for the button and LED pins and save to local variables
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    m_buttonPin = buttonPin;
    m_ledPin = ledPin;
    m_numberStates = numStates;

    // Initially, button is off and released.
    m_state = false;
    m_pressed = false;

    // Last action was at t = 0
    m_timeOfAction = 0;

    // Haven't done anything yet
    m_numberOfActions = 0;
}

button::button() {

}

void button::setButtonProperties(int buttonPin, int ledPin, int numStates) {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    m_buttonPin = buttonPin;
    m_ledPin = ledPin;
    m_numberStates = numStates;

    // Initially, button is off and released.
    m_state = false;
    m_pressed = false;

    // Last action was at t = 0
    m_timeOfAction = 0;

    // Haven't done anything yet
    m_numberOfActions = 0;

}

bool button::stateChanged() {
    // Read the button pin
    bool val = digitalRead(m_buttonPin);

    // How long since the last button action?
    unsigned long currentTime = millis();
    unsigned long timeSinceAction = currentTime-m_timeOfAction;

    // If it has been long enough, then check to see if a press or release action has occurred
    if (timeSinceAction > 100) {
        if (val != m_pressed) {

	    // OK, we have a new action.  Update the time of action and update the pressed/released state
            m_timeOfAction = currentTime;
            m_pressed = val;

            if (m_pressed) {

                // If this is a button press, then toggle the on/off state and update the LED.
                if (++m_state >= m_numberStates) {
                    m_state = 0;
                }

	        digitalWrite(m_ledPin, m_state);

        	// And update the count of number of actions.
	        m_numberOfActions++;

                return true;

            } // if (m_pressed)

        } // if (val != m_pressed)

    } // if (timeSinceAction > 100)

    return false;
}

int button::getState() {
    return m_state;
};

void button::setState(int state) {
    // Just overwrite the new state
    m_state = state;
    // Update the LED pin
    digitalWrite(m_ledPin, m_state);

    // Update the number of actions
    m_numberOfActions++;
}

int button::getNumberOfActions() {
    return m_numberOfActions;
}
