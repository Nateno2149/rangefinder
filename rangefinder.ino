#include "rgb_lcd.h"
rgb_lcd lcd;
uint8_t rangePin = 5;
uint8_t togglePin = 4;
uint8_t calibratePin = 3;
uint8_t prevtoggleState;
uint8_t currtoggleState;

void setup() {
  pinMode(togglePin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 1);
  currtoggleState = digitalRead(togglePin);
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
  prevtoggleState = currtoggleState;
  currtoggleState = digitalRead(togglePin);
  if (prevtoggleState == LOW && currtoggleState == HIGH) {
    lcd.clear();
    lcd.print(cmConversion());
    lcd.setCursor(1, 1);
    delay(300);
    Serial.println("centimeters");
  } else {
    lcd.clear();
    lcd.print(inchConversion());
    lcd.setCursor(1, 1);
    delay(300);
    Serial.println("inches");
  }
  Serial.println(prevtoggleState);
  Serial.println(currtoggleState);
}


//float calibrateMode() {}
//float errorMessage() {}

//500mm for 1100 pulse
