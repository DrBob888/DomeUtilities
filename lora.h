class lora
{
	public:
	#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		lora();
	#else
		lora(int txPin, int rxPin);
	#endif
	
	int send(const char* command, char* response, buflen);
	int receive(char* response, int buflen);
	bool available();
	
	private:
	#if ndefined(__AVR_ATmega1280__) && ndefined(__AVR_ATmega2560__)
		SoftwareSerial *m_port;
	#endif
}