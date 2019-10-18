<include lora.h>

lora myLora;

#define BUFLEN 64;
char workingBuffer[BUFLEN];

void setup() {
	Serial.begin(9600);
	myLora.send("AT+ADDRESS?", workingBuffer, BUFLEN);
	myLora.send("AT+NETWORKID?", workingBuffer, BUFLEN);
	myLora.send("AT+PARAMETER=10,7,1,7", workingBuffer, BUFLEN);
	myLora.send("AT+PARAMETER?",workingBuffer, BUFLEN);
}

void loop() {
	if (myLora.available()) {
		myLora.receive(workingBuffer, BUFLEN);
		Serial.println(workingBuffer);
	}
	
	if (Serial.available() > 0) {
		String str = "AT+" + Serial.readString();
		str.remove(str.length() - 1, 1);
		Serial.println(str);
		myLora.send(str);
	}
}
