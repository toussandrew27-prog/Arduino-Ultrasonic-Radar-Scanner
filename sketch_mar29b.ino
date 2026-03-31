#include <LiquidCrystal.h>
#include <Servo.h>
#include "led_rgb.h"

// --- LCD ---
LiquidCrystal lcd (12, 13, 4, 6, 7, 8);

// --- SERVO ---
int angle = 0;
Servo monServo;

// --- BUZZER ---
int pinBuzzer = 5;
unsigned long dernierbip = 0;

// --- ULTRASON ---
const int TrigPin = A0;
const int EchoPin = A1;
long duree;
int distance;

void setup() 
{
  lcd.begin(16 , 2);
  lcd.print("Distance:"); // texte fixe
  monServo.attach(3);
  setupRGB(11, 10, 9);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  Serial.begin(9600); // Ouvre le canal de communication avec le PC
}

void loop()
{

  for(angle = 0; angle <= 180; angle += 1)
  {

   unsigned long bipActuel = millis();

   monServo.write(angle);
   delay(15);

   digitalWrite(TrigPin, LOW);
   delayMicroseconds(5);

   digitalWrite(TrigPin, HIGH);
   delayMicroseconds(15);
   digitalWrite(TrigPin, LOW);

   duree = pulseIn(EchoPin, HIGH);

   distance = duree * 0.034/2;

   // --- ENVOI DES DONNÉES AU PC ---
   Serial.print(angle);
   Serial.print(",");
   Serial.print(distance);
   Serial.print(".");

   lcd.setCursor(0, 0);
   lcd.print("Distance:       ");

   lcd.setCursor(0, 0);
   lcd.print("Distance : ");
   lcd.print(distance);
   lcd.print(" cm");

  if(distance >= 10)

  {
    setColor(0, 255, 0);
    
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("Rien en vue");

    if (bipActuel - dernierbip >= 3000)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

  if(distance < 10 && distance >= 5)

  {
    setColor(255, 255, 0);

    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("objet repere");

    if (bipActuel - dernierbip >= 1000)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

   if(distance < 5)

  {
    setColor(255, 0, 0);
    
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("ALERTE ROUGE !");

    if (bipActuel - dernierbip >= 200)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

  }

  for(angle = 180; angle != 0; angle -= 1)
  {
   
   unsigned long bipActuel = millis();

   monServo.write(angle);
   delay(15);

   digitalWrite(TrigPin, LOW);
   delayMicroseconds(5);

   digitalWrite(TrigPin, HIGH);
   delayMicroseconds(15);
   digitalWrite(TrigPin, LOW);

   duree = pulseIn(EchoPin, HIGH);

   distance = duree * 0.034/2;

   // --- ENVOI DES DONNÉES AU PC ---
   Serial.print(angle);
   Serial.print(",");
   Serial.print(distance);
   Serial.print(".");

   lcd.setCursor(0, 0);
   lcd.print("Distance:       ");

   lcd.setCursor(0, 0);
   lcd.print("Distance : ");
   lcd.print(distance);
   lcd.print(" cm");

  if(distance >= 10)

  {
    setColor(0, 255, 0);
    
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("Rien en vue");

    if (bipActuel - dernierbip >= 3000)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

  if(distance < 10 && distance >= 5)

  {
    setColor(255, 255, 0);

    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("objet repere");

    if (bipActuel - dernierbip >= 1000)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

   if(distance < 5)

  {
    setColor(255, 0, 0);
    
    lcd.setCursor(0, 1);
    lcd.print("                ");

    lcd.setCursor(0, 1);
    lcd.print("ALERTE ROUGE !");

    if (bipActuel - dernierbip >= 200)
    {
      dernierbip = bipActuel;
      tone(pinBuzzer, 1000, 100);
    }
  }

  }

}
