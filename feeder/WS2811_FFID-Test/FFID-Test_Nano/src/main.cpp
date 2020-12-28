#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, 2, NEO_RGB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  pixel.begin();
  pixel.show(); // Initialize all pixels to 'off'

}

void loop() {
  // put your main code here, to run repeatedly:


  delay(2000);

  int i = round(random(0,255));

  pixel.setPixelColor(0, i, i, i);

  Serial.println(i);

  pixel.show();

}