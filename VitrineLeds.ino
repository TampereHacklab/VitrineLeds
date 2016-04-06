/*
   Tampere Hacklab vitrine led lights
   96 Neopixels, 32 per cabinet, 3 cabinets
   install neopixel library from https://github.com/adafruit/Adafruit_NeoPixel
   and pro micro 5v/16mhz from https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6 //Neopixel strip data is connected to pin 6
#define LEDS 96

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800); //Initialize neopixel library

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  colorWipeLeft(strip.Color(255, 0, 0), 50); // Red
  colorWipeLeft(strip.Color(0, 255, 0), 50); // Green
  colorWipeLeft(strip.Color(0, 0, 255), 50); // Blue
  colorWipeLeft(strip.Color(255, 255, 255), 50); // White
  delay(10000);
  colorWipeRight(strip.Color(255, 0, 0), 50); // Red
  colorWipeRight(strip.Color(0, 255, 0), 50); // Green
  colorWipeRight(strip.Color(0, 0, 255), 50); // Blue
  colorWipeRight(strip.Color(255, 255, 255), 50); // White
  delay(10000);
  sideFillRight(strip.Color(255, 0, 0), 50); // Red
  sideFillRight(strip.Color(0, 255, 0), 50); // Green
  sideFillRight(strip.Color(0, 0, 255), 50); // Blue
  sideFillRight(strip.Color(255, 255, 255), 50); // White
  delay(10000);

}

// Fill the dots one after the other with a color
void colorWipeLeft(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void colorWipeRight(uint32_t c, uint8_t wait) {
  for (uint16_t i = strip.numPixels(); i > 0; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void sideFillRight(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < (strip.numPixels() / 2); i++) { // fill strip from sides to middle
    strip.setPixelColor(i, c);
    strip.setPixelColor(strip.numPixels() - i, c);
    strip.show();
    delay(wait);
  }
}

