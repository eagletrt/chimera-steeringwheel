#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(52, INPUT);
}

byte x = 0;
boolean button = false;
boolean previous = false;

void loop() {
  
  if(digitalRead(52) == HIGH){
    button = true;
  }
  else{
    button = false;
  }
  
  if(button == true){
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(1);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  if(button == false){
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(0);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }
}
