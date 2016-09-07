#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            2

#define NUMPIXELS      30

enum CHAR_LEDS {
  LR = 1, LS, LT, LU, LV, LW, LX, LY, LZ, NAN1, LQ,
  LP, LO, LN, LM, LL, LK, LJ, LI, NAN2, LA, LB, LC,
  LD, LE, LF, LG, LH
};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 500; // delay for half a second

void setup() 
{
  Serial.begin(115200);
  pixels.begin(); 
}

void loop()
{
  if (Serial.available() > 0)
  {
    char inchar = Serial.read();
    switch(inchar)
    {
      case 'a':
      case 'A':
        lightUp(LA);
        break;
        
      case 'b':
      case 'B':
        lightUp(LB);
        break;
      case 'c':
      case 'C':
        lightUp(LC);
        break;
      case 'd':
      case 'D':
        lightUp(LD);
        break;
      case 'e':
      case 'E':
        lightUp(LE);
        break;
      case 'f':
      case 'F':
        lightUp(LF);
        break;
      case 'g':
      case 'G':
        lightUp(LG);
        break;
      case 'h':
      case 'H':
        lightUp(LH);
        break;
      case 'i':
      case 'I':
        lightUp(LI);
        break;
      case 'j':
      case 'J':
        lightUp(LJ);
        break;
      case 'k':
      case 'K':
        lightUp(LK);
        break;
      case 'l':
      case 'L':
        lightUp(LL);
        break;
      case 'm':
      case 'M':
        lightUp(LM);
        break;
      case 'n':
      case 'N':
        lightUp(LN);
        break;
      case 'o':
      case 'O':
        lightUp(LO);
        break;
      case 'p':
      case 'P':
        lightUp(LP);
        break;
      case 'q':
      case 'Q':
        lightUp(LQ);
        break;
      case 'r':
      case 'R':
        lightUp(LR);
        break;
      case 's':
      case 'S':
        lightUp(LS);
        break;
      case 't':
      case 'T':
        lightUp(LT);
        break;
      case 'u':
      case 'U':
        lightUp(LU);
        break;
      case 'v':
      case 'V':
        lightUp(LV);
        break;
      case 'w':
      case 'W':
        lightUp(LW);
        break;
      case 'x':
      case 'X':
        lightUp(LX);
        break;
      case 'y':
      case 'Y':
        lightUp(LY);
        break;
      case 'z':
      case 'Z':
        lightUp(LZ);
        break;
      default:
        break;
    }
  }
}

void lightUp(CHAR_LEDS charIndex)
{
  pixels.setPixelColor(charIndex, pixels.Color(255,255,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(charIndex, pixels.Color(0,0,0));
  pixels.show();
}

