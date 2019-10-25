#include "buttonClass.h"
#include "Arduino.h"

//check if debounce delay has been changed elsewhere
#ifndef DEBOUNCE_DELAY
#define DEBOUNCE_DELAY 100
#endif

button::button(int buttonPin, int ledPin, int numStates, bool onlyTwoStates) {

    // Set the pin modes for the button and LED pins and save to local variables
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    m_buttonPin = buttonPin;
    m_ledPin = ledPin;
    m_numberStates = numStates;
	m_onlyOnOff = onlyTwoStates;

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

void button::setButtonProperties(int buttonPin, int ledPin, int numStates, bool onlyTwoStates) {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    m_buttonPin = buttonPin;
    m_ledPin = ledPin;
    m_numberStates = numStates;
	m_onlyOnOff = onlyTwoStates; //used for forcing specific buttons to only have two states
								 //while the corresponding dome can have more

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
    if (timeSinceAction > DEBOUNCE_DELAY) {
        if (val != m_pressed) {

	    // OK, we have a new action.  Update the time of action and update the pressed/released state
            m_timeOfAction = currentTime;
            m_pressed = val;

            if (m_pressed) {
				m_state++;
                // If this is a button press, then increment state and update LED
                if (m_state >= m_numberStates || (m_state > 1 && m_onlyOnOff)) {
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
