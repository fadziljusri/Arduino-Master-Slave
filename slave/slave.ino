// Include the required Wire library for I2C
#include <Wire.h>

int LED = 13;
int x = 0;

void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  //If value received is 0 blink LED
  if (x == 0) {
    digitalWrite(LED, LOW);
    delay(1000);
    Serial.println("LED off");
  }
  //If value received is 3 blink LED
  if (x == 1) {
    digitalWrite(LED, HIGH);
    delay(1000);
    Serial.println("LED on");
  }
}

