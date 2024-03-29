class button
{
  public:
    // Set the button and led pins.  Set number of different states.  
    // Each push of the button advances the state by one.  When max states
    // is exceeded, the state wraps back to zero.  Note that a button with 
    // only two states will toggle on and off each time it is pressed.
	// a button forced to onlyTwoStates will only toggle between two states,
	// but the corresponding dome can have more states (multicolor domes)
    button(int buttonPin, int ledPin, int numStates, bool onlyTwoStates);
    button();
    void setButtonProperties(int buttonPin, int ledPin, int numStates, bool onlyTwoStates);

    // Returns true if state changed
    bool stateChanged();
  
    // Returns the current state of the button (false = off, true = on)
    int getState();

    // Sets the state of the button
    void setState(int state);

    // Returns total number of button state changes
    int getNumberOfActions();

  private:
    // button and led pins
    int m_buttonPin;
    int m_ledPin;
	
	//button only has access to two states
	bool m_onlyOnOff;
  
    // Number of states
    int m_numberStates;

    // time of last action (used to debounce)
    unsigned long m_timeOfAction;

    // Button "on" or "off" state
    int m_state;

    // Button pressed or released state
    bool m_pressed;
  
    // Button has been changed
    bool m_changed;

    // Total number of state changes
    int m_numberOfActions;
};
