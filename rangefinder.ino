<<<<<<< HEAD
=======
/*
Nice - good use of descriptive variable names and functions.
*/
>>>>>>> 63cb66daece43b763c286459528e73c3291578db

#include "rgb_lcd.h"
rgb_lcd lcd;
uint8_t rangePin = 5;
uint8_t togglePin = 12;
uint8_t calibratePin = 3;
uint8_t buttonHold = 0;
uint8_t prevMode = LOW;
uint8_t Mode;
bool State = 0;
<<<<<<< HEAD
bool errorState = 0;
=======
>>>>>>> 63cb66daece43b763c286459528e73c3291578db

void setup() {
  pinMode(togglePin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 1);
}

uint64_t rangeFinder(uint8_t rangePin) {
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
<<<<<<< HEAD
  }
  uint64_t rawValue = rangeFinder(rangePin);
  if (rawValue == 2047 || rawValue == 0 || rawValue == 2222) {
    errorState = 1;
    if (rawValue == 2047) {
      lcd.clear();
      lcd.print("ERROR: TOO FAR!");
      lcd.setCursor(1, 1);
      delay(300);
    }
    if (rawValue == 0 || 2222) {
      lcd.clear();
      lcd.print("ERROR: INVALID MEASUREMENT!");
      lcd.setCursor(1, 1);
      delay(300);
    }

  }

  else {
    errorState = 0;
  }
  if (State == HIGH && errorState == 0) {
=======
  }

/* 
  Since state can ONLY equal High or Low it makes more sense to use an if / else rather than two ifs.
  e.g.

  if(State == HIGH)
  {
      .....  Do the State is high stuff here
  }
  else
  {  
      ..... Do the State is low stuff here
  }

*/
  
  if (State == HIGH) {
>>>>>>> 63cb66daece43b763c286459528e73c3291578db
    lcd.clear();
    lcd.print(cmConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }
<<<<<<< HEAD
  if (State == LOW && errorState == 0) {
=======
  if (State == LOW) {
>>>>>>> 63cb66daece43b763c286459528e73c3291578db
    lcd.clear();
    lcd.print(inchConversion());
    lcd.setCursor(1, 1);
    delay(300);
  }
  Serial.print("Mode = ");
  Serial.println(Mode);
<<<<<<< HEAD
  Serial.print("prevMode = ");
=======
    Serial.print("prevMode = ");
>>>>>>> 63cb66daece43b763c286459528e73c3291578db
  Serial.println(digitalRead(prevMode));
  Serial.print("State = ");
  Serial.println(digitalRead(State));
  Serial.print("togglePin = ");
  Serial.println(digitalRead(togglePin));
<<<<<<< HEAD
  Serial.print("Error State = ");
  Serial.println(errorState);
=======
>>>>>>> 63cb66daece43b763c286459528e73c3291578db
}






//float calibrateMode() {}

//500mm for 1100 pulse
