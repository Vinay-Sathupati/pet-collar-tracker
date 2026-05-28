#include "modem_handler.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1152000);

  delay(2000);

  Serial.println();
  Serial.println("=======================");
  Serial.println("Pet Collar Starting....");
  Serial.println("=======================");

  modemInit();
  sendATCommand("ATE0", 1000);
  sendATCommand("AT", 1000);
  sendATCommand("AT+CPIN?", 1000);
  sendATCommand("AT+CSQ", 1000);
  sendATCommand("AT+CREG?", 1000);
  sendATCommand("AT+QGPS=1", 3000);

  delay(5000);

  sendATCommand("AT+QGPSLOC?",5000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
