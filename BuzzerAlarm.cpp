/**
 * Created By Claudio <p3lpz> Cavalcante - July 14, 2020
 * At a Pandemic Home Office - XD
 */

#include "pitches.h"
#include "BuzzerAlarm.h"

#define FALSE 0
#define TRUE 1


/**
 * Constructor
 */
BuzzerAlarm::BuzzerAlarm(byte pin) {
  this->_pin = pin;

  init();
}

void BuzzerAlarm::init() {

  pinMode(_pin, OUTPUT);
  lastPause = 0, lastBeep = 0, beeped = FALSE, notePlayed = 0; 

  melody[0] = NOTE_C4;
  melody[1] = NOTE_E4;
  melody[2] = NOTE_G4;
  melody[3] = NOTE_C5;

  khzToBeep = 1000;
}

void BuzzerAlarm::beep() {
  if (beeped ==  FALSE) {
    tone(_pin, melody[notePlayed++], khzToBeep);
    beeped = TRUE;
  } else {
    noTone(_pin);
    beeped = FALSE;
  }
}

void BuzzerAlarm::wakeUp() {
  int now = millis();

  int lastBeepDiff = now - lastPause; // To check the time to do the big pause on beeps

  if (now - lastPause > 800) {
    if (beeped == TRUE) {
      beep();
    }


    if (now - lastPause >= 1000) {
      lastBeep = now;

      lastPause = now; 

      notePlayed = 0;
    };

  } else if (now - lastBeep > 88) {

    lastBeep = now;
    
    beep();

  }
}
