#include <HardwareSerial.h>

HardwareSerial gsm(1);

void setup() {
  // Start communication with the GSM module
  gsm.begin(9600, SERIAL_8N1, 16, 17); // RX, TX
  Serial.begin(115200); // Communication with the PC
  Serial.println("SIM800 Module Testing...");

  // Wait for the GSM module to initialize
  delay(1000);

  // Send an SMS
  sendSMS("+1234567890", "Hello from ESP32!"); // Replace with your phone number
}

void loop() {
  // Nothing to do here
}

void sendSMS(const char* phoneNumber, const char* message) {
  gsm.println("AT"); // Send AT command to check if the module is responding
  delay(1000);

  gsm.println("AT+CMGF=1"); // Set SMS mode to text
  delay(1000);

  gsm.print("AT+CMGS=\""); // Start sending SMS
  gsm.print(phoneNumber);  // Phone number to send the SMS
  gsm.println("\"");
  delay(1000);

  gsm.println(message); // The message to send
  delay(1000);

  gsm.write(26); // ASCII code for Ctrl+Z to send the message
  delay(1000);

  Serial.println("SMS sent successfully!");
}
