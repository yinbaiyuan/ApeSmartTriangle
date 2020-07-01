#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 15

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 4
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  Serial.println("resetting");
  LEDS.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(200);
  pinMode(10, INPUT);
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}

int displayMode = 0;
int d10Status = 0;
void loop() {
  if (digitalRead(10) == 0)
  {
    if (d10Status == 0)
    {
      displayMode++;
      displayMode %= 3;
      d10Status = 1;
      Serial.println(displayMode);
    }
  } else
  {
    d10Status = 0;
  }
  switch (displayMode)
  {
    case 0: showOne(); break;
    case 1: showTwo(); break;
    case 2: showThree(); break;
  }
  
}
void showOne()
{
  static uint8_t hue = 0;
//  Serial.print("x");
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
  }
  hue++;
  FastLED.show();
  delay(10);
}
void showTwo()
{
  static uint8_t hue = 0;
//  Serial.print("x");
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((hue + i*10) % 256, 255, 255);
  }
  hue++;
  FastLED.show();
  delay(10);
}
void showThree()
{
  static uint8_t hue = 0;
//  Serial.print("x");
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, 255, 255);
  }
  hue++;
  FastLED.show();
  randomSeed(analogRead(A0)); 
  delay(random(10,50));
}
