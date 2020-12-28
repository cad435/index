#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, 2, NEO_RGB + NEO_KHZ800);


uint8_t i = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  pixel.begin();
  pixel.show(); // Initialize all pixels to 'off'

}

void loop() {
  // put your main code here, to run repeatedly:


  delay(1000);

  pixel.setPixelColor(0, i, i, i);

  Serial.println(i);

  pixel.show();

  i++; //will overflow and reset to 0 after overflow
}