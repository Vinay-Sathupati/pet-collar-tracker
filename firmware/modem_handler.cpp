#include <Arduino.h>
#include "modem_handler.h"

HardwareSerial modemSerial(1);

#define MODEM_RX 12
#define MODEM_TX 13

void modemInit() {
  Serial.println("Initializing modem UART...");
  
  modemSerial.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);

  delay(3000);

  Serial.println("Modem UART initialized");
}

bool sendATCommand(const char* command, unsigned long timeout) {

  while (modemSerial.available()) {
    modemSerial.read();
  }

  Serial.println();
  Serial.print("Sending command: ");
  Serial.println(command);

  modemSerial.println(command);
  
  String response = "";
  unsigned long startTime = millis();

  while ((millis() - startTime) < timeout) {
    while (modemSerial.available()) {
      char c = modemSerial.read();
      response += c;

      Serial.write(c);
    }

    if (response.indexOf("OK") != -1) {
      Serial.println();
      return true;
    }

    if (response.indexOf("ERROR") != -1) {
      Serial.println();
      return false;
    }

    delay(10);
  }
  Serial.println("\nTimeout waiting for response");

  return false;
}
