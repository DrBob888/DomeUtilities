class button
{
  public:
    button(int pin);
    int getState();
  private:
    int m_pin;
    unsigned long m_timeOfAction;
    int m_state;
    int m_numberActions;
};
