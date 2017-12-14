#include <Wire.h>

#define red_led 4
#define green_led 3
#define blue_led 2

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  analogWrite(red_led, 255);
  analogWrite(green_led, 255);
  analogWrite(blue_led, 255);
  Serial.begin(9600);

  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115000);           // start serial for output
}

int c = 0;

void loop()
{
  delay(10);
}

void receiveEvent(int howMany) {
  c = 0;
  while (Wire.available() > 0) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
  }
  if (c == 1) {
    if (Serial.available()) {
      char led_specifier = Serial.read();
      int led_brightness = Serial.parseInt();
      write_leds(led_specifier, led_brightness);
    }
  }


}
void write_leds(char led, int brightness)
{
  if (led == 'r') {
    analogWrite(red_led, 255 - brightness);
    return;
  }
  if (led == 'g') {
    analogWrite(green_led, 255 - brightness);
    return;
  }
  if (led == 'b') {
    analogWrite(blue_led, 255 - brightness);
    return;
  }

  return;
}


