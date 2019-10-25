#include <lora.h>

lora myLora;
//lora myLora(5,6);

#define BUFLEN 64
char workingBuffer[BUFLEN];

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Starting...");
  myLora.send("AT+ADDRESS?");
  myLora.receive(workingBuffer,BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+NETWORKID?");
  myLora.receive(workingBuffer,BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+PARAMETER=10,7,1,7");
  myLora.receive(workingBuffer,BUFLEN);
  Serial.println(workingBuffer);
  myLora.send("AT+PARAMETER?");
  myLora.receive(workingBuffer,BUFLEN);
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
    myLora.send(str.c_str());
    myLora.receive(workingBuffer,BUFLEN);

    Serial.println(workingBuffer);
  }
}
