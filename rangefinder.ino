#include "rgb_lcd.h"
rgb_lcd lcd;
uint8_t rangePin = 5;
uint8_t togglePin = 12;
uint8_t calibratePin = 3;
uint8_t buttonHold = 0;
uint8_t Mode = 0;


void setup() {
  pinMode(togglePin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 1);
}

float rangeFinder(uint8_t rangePin) {
  uint64_t duration;
  digitalWrite(rangePin, LOW);
  pinMode(rangePin, OUTPUT);
  digitalWrite(rangePin, HIGH);
  delayMicroseconds(2);
  digitalWrite(rangePin, LOW);
  pinMode(rangePin, INPUT);
  duration = pulseIn(rangePin, HIGH);
  return duration;
}

float inchConversion() {
  float inch = rangeFinder(rangePin) * 0.01789545;
  return inch;
}

float cmConversion() {
  float cm = rangeFinder(rangePin) * 0.045;
  return cm;
}

void loop() {
  if (digitalRead(togglePin) == HIGH && buttonHold == 0) {
    buttonHold = 1;
    if (Mode == LOW) {
      Mode = HIGH;
    }
    if (Mode == HIGH) {
      Mode = LOW;
    }
  }
  if (digitalRead(togglePin) == LOW) {
    buttonHold = 0;
  }

  if (Mode == HIGH) {
    lcd.clear();
    lcd.print(cmConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }
  if (Mode == HIGH) {
    lcd.clear();
    lcd.print(inchConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }

}






//float calibrateMode() {}
//float errorMessage() {}

//500mm for 1100 pulse
