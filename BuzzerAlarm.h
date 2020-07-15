/**
 * Created By Claudio <p3lpz> Cavalcante - July 14, 2020
 * At a Pandemic Home Office - XD
 */

#ifndef BUZZER_ALARM_H
#define BUZZER_ALARM_H

#include <Arduino.h>

class BuzzerAlarm {
  private:
    byte _pin;
    int lastBeep;
    // save the millisecond that executed a beep pause
    int lastPause;
    int melody[4]; // Melody that will be played | Must be 4 notes
    int beeped; // beep state

    int notePlayed; // The note played by melody array
    int khzToBeep; //KHz to beep

    void init();

  public:
    BuzzerAlarm(byte pin);
    int timesPlayed;
    void beep(); // active/inactive beep base on beeped var
    void wakeUp(); // run the alarm
    void stop();
};

#endif
