#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(52, INPUT);
}

byte x = 0;

void loop() {
  if(digitalRead(52) == HIGH){
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(1);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if(digitalRead(52) == LOW){
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(0);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
}
