#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            2

#define NUMPIXELS      4
//was 30

enum CHAR_LEDS {
  LR = 1, LC, LB, LA
};


//enum CHAR_LEDS {
//  LR = 1, LS, LT, LU, LV, LW, LX, LY, LZ, NAN1, LQ,
//  LP, LO, LN, LM, LL, LK, LJ, LI, NAN2, LA, LB, LC,
//  LD, LE, LF, LG, LH
//};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 500; // delay for half a second

void setup() 
{
  Serial.begin(115200);
  pixels.begin(); 
}

void loop()
{
 pixels.setPixelColor(0, pixels.Color(255,255,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(1, pixels.Color(255,255,255));
  pixels.show();
  delay(delayVal);
   pixels.setPixelColor(0, pixels.Color(0,0,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(1, pixels.Color(0,0,255));
  pixels.show();
  delay(delayVal);
     pixels.setPixelColor(0, pixels.Color(0,255,0));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(1, pixels.Color(0,255,0));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(2, pixels.Color(0,255,0));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(1, pixels.Color(0,255,0));
  pixels.show();
  delay(delayVal);
   pixels.setPixelColor(0, pixels.Color(255,0,0));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(2, pixels.Color(123,321,223));
  pixels.show();
  delay(delayVal);
     pixels.setPixelColor(0, pixels.Color(90,25,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(1, pixels.Color(123,321,223));
  pixels.show();
  delay(delayVal);
}

void lightUp(CHAR_LEDS charIndex)
{
  pixels.setPixelColor(charIndex, pixels.Color(255,255,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(charIndex, pixels.Color(0,0,0));
  pixels.show();
  delay(delayVal);
}

