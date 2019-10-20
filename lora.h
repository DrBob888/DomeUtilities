#include <SoftwareSerial.h>

class lora
{
public:
	// If this is a MEGA, then we will use Serial1 to talk to the LoRa.
	// otherwise, this is a Nano and we use SoftwareSerial.
	#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	lora();
	#else
	lora(int txPin, int rxPin);
	#endif

	// Sends a command to the LoRa.  Note that all commands start with "AT+"
	void send(const char* command);

	// Receives characters from the LoRa.  Note this will block until the "\n"
	// character is received.  Check to make sure there are characters in the
	// buffer before using.
	int receive(char* response, int buflen);

	// Check to see if there is a character available.
	bool available();

private:
	// If we are using SoftwareSerial, then we need to create a pointer to our
	// object.
	#if !defined(__AVR_ATmega1280__) && !defined(__AVR_ATmega2560__)
	SoftwareSerial *m_port;
	#endif
};
