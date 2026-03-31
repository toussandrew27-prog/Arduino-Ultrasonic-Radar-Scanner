#include "Arduino.h"
#include "led_rgb.h"

static int pinRouge = 11, pinVert = 10, pinBleu = 9;

void setupRGB(int pinR, int pinV, int pinB)

{
  pinRouge = pinR;
  pinVert = pinV;
  pinBleu = pinB;

  pinMode(pinRouge, OUTPUT);
  pinMode(pinVert, OUTPUT);
  pinMode(pinBleu, OUTPUT);
}

void setColor(int rouge, int vert, int bleu)

{
  analogWrite(pinRouge, rouge);
  analogWrite(pinVert, vert);
  analogWrite(pinBleu, bleu);
}