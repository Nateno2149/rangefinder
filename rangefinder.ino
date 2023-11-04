#include "rgb_lcd.h"
rgb_lcd lcd;
uint8_t rangePin = 5;
uint8_t togglePin = 12;
uint8_t calibratePin = 3;
uint8_t buttonHold = 0;
uint8_t prevMode = LOW;
uint8_t Mode;
bool State = 0;

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
  Mode = digitalRead(togglePin);
  if (Mode != prevMode) {
    if (Mode == HIGH) {
      State = !State;
    }
    prevMode = Mode;
  }

  if (State == HIGH) {
    lcd.clear();
    lcd.print(cmConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }
  if (State == LOW) {
    lcd.clear();
    lcd.print(inchConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }
  Serial.print("Mode = ");
  Serial.println(Mode);
    Serial.print("prevMode = ");
  Serial.println(digitalRead(prevMode));
  Serial.print("State = ");
  Serial.println(digitalRead(State));
  Serial.print("togglePin = ");
  Serial.println(digitalRead(togglePin));
}






//float calibrateMode() {}
//float errorMessage() {}

//500mm for 1100 pulse
