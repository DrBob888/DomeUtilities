#include <lora.h>

lora myLora;

#define BUFLEN 64
char workingBuffer[BUFLEN];

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Starting...");
  myLora.send("AT+ADDRESS?", workingBuffer, BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+NETWORKID?", workingBuffer, BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+PARAMETER=10,7,1,7", workingBuffer, BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+PARAMETER?", workingBuffer, BUFLEN);
  Serial.println(workingBuffer);
}

void loop() {
  if (myLora.available()) {
    Serial.println("LoRa received");

    myLora.receive(workingBuffer, BUFLEN);
    Serial.println(workingBuffer);
  }

  if (Serial.available() > 0) {
    String str = "AT+" + Serial.readString();
    str.remove(str.length() - 1, 1);
    Serial.println(str);
    myLora.send(str.c_str(), workingBuffer, BUFLEN);
    Serial.println(workingBuffer);
  }
}
