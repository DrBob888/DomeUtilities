class button
{
  public:
    button(int buttonPin, int ledPin);

	// Returns the current state of the button (false = off, true = on)
    bool getState();

	// Sets the state of the button
	void setState(bool state);

	// Returns total number of button state changes
	int getNumberOfActions();


  private:
	// button and led pins
    int m_buttonPin;
	int m_ledPin;

	// time of last action (used to debounce)
    unsigned long m_timeOfAction;

	// Button "on" or "off" state
    bool m_state;

	// Button pressed or released state
	bool m_pressed;

	// Total number of state changes
    int m_numberActions;
};
