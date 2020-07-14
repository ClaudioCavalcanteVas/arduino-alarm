#include "pitches.h"

#define TRUE 1
#define FALSE 0

const unsigned int buzzerPin = 5;

unsigned int lastBip = 0, lastPause = 0;
unsigned int beeped = FALSE;

const unsigned int khzBip = 1000;

void setup() {
  
  pinMode(buzzerPin, OUTPUT);

}

unsigned int notePlayed = 0;

int melody[]  = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5
};

int counter = 0;

void beep() {
  if (beeped ==  FALSE) {
    tone(buzzerPin, melody[notePlayed++], khzBip);
    beeped = TRUE;
  } else {
    noTone(buzzerPin);
    beeped = FALSE;
  }
}

void loop() {
  
  int now = millis();

  if (now - lastPause > 800) {
    if (beeped == TRUE) {
      beep();
    }


    if (now - lastPause >= 1000) {
      lastBip = now;

      lastPause = now; 

      notePlayed = 0;
    };

  } else if (now - lastBip > 88) {

    lastBip = now;
    
    beep();

  } else {

  }

}
