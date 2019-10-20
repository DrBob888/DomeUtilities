#include "lora.h"
#include "arduino.h"

// Constuctor.  If this is a Mega, then we just start Serial1.  If it is a
// Nano, then create the SoftwareSerial object and then start it
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	lora::lora() {
		Serial1.begin(9600);
	}
#else
	lora::lora(int txPin, int rxPin) {
		*m_port = SoftwareSerial(txPin, rxPin);
		m_port->begin(9600);
	}
#endif

// Append terminator and send
void lora::send(const char* command) {
	#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		Serial1.print(command);
		Serial1.print("\r\n");
	#else
		m_port->print(command);
		m_port->print("\r\n");
	#endif
}

// Read characters until we get the terminator.
int lora::receive(char* response, int buflen) {
	#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		int n = Serial1.readBytesUntil('\n', response, buflen);
	#else
		int n = m_port->readBytesUntil('\n', response, buflen);
	#endif
	response[n-1] = 0;
	return n;
}

// Check to see if characters are available.
bool lora::available() {
	#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
		bool ret = Serial1.available() > 0;
	#else
		bool ret = m_port->available() > 0;
	#endif

	return ret;
}
