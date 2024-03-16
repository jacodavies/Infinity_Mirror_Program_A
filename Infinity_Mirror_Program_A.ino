/* Created by Jacob Davis  March 16, 2024 
intended for use in an infinity mirror with 150 count WS2812 addressable led strip 
ENJOY! :) */
#include <FastLED.h>     //use the FastLed
#define LED_B       13   //status light pin/built-in led
#define LED_PIN     36   //addressable led strip pin
#define NUM_LEDS    150  //number of leds
#define ELS    0    //ExteriorLedStart
#define ELE    30   //ExteriorLedEnd
#define IMLS   33   //InfinityMirrorLedStart
#define IMLE   141  //InfinityMirrorLedEnd
int t = 0;
int y = 0;
CRGB leds[NUM_LEDS];
void setup() {
  pinMode(LED_B, OUTPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.show();
  //starting sequence begins
  delay(1000);
  leds[32] = CRGB (255, 255, 255);
  FastLED.show();
  digitalWrite(LED_B, HIGH);
  delay(1000);
  leds[32] = CRGB (0, 0, 0);
  FastLED.show();
  digitalWrite(LED_B, LOW);
  delay(1000);
  for (int x = IMLE; x >= IMLS; x--) {
    for (int z = 0; z <= 100; (z = z + 10)) {
      leds[((x)+0)] = CRGB (0, 0, z);
      delay(5);
      FastLED.show();
    }
  }
}
void loop() {
  //the progress bar fills up before it continues to the next stage
  for (int i = ELS; i <= (ELE - 1); i++) {
    for (int z = 0; z <= 20; z++) {
      leds[((i)+0)] = CRGB ( z, 0, 0);
      FastLED.show();
      delay(10);
    }
  }
  digitalWrite(LED_B, HIGH);
  //decide which color to transition to next
  y++;
  if (y == 1) {
    for (int x = IMLE; x >= IMLS; x--) {
      for (int z = 0; z <= 100; (z = z + 10)) {
        leds[((x)+0)] = CRGB ( 0, z, (100 - z));
        delay(5);
        FastLED.show();
      }
    }
  }
  if (y == 2) {
    for (int x = IMLE; x >= IMLS; x--) {
      for (int z = 0; z <= 100; (z = z + 10)) {
        leds[((x)+0)] = CRGB ( z, (100 - z), 0);
        delay(5);
        FastLED.show();
      }
    }
  }
  if (y == 3) {
    for (int x = IMLE; x >= IMLS; x--) {
      for (int z = 0; z <= 100; (z = z + 10)) {
        leds[((x)+0)] = CRGB ((100 - z), 0, z);
        delay(5);
        FastLED.show();
      }
    }
  y = 0;
  }
  //empty the progress bar and start again
  for (int i = (ELE - 1); i >= ELS; i--) {
    for (int z = 20; z >= 0; (z = z - 5)) {
      leds[((i)+0)] = CRGB ( z, 0, 0);
      FastLED.show();
      delay(3);
    }
  }
  digitalWrite(LED_B, LOW);
}
