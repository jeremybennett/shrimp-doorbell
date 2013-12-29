/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"
 #include <avr/sleep.h>
 #include <avr/wdt.h>

// notes in the melody:
int melody[] = {
  NOTE_E4,  NOTE_GS4, NOTE_FS4, NOTE_B3,
  NOTE_E4,  NOTE_FS4, NOTE_GS4, NOTE_E4,
  NOTE_GS4, NOTE_E4,  NOTE_FS4, NOTE_B3,
  NOTE_B3,  NOTE_FS4, NOTE_GS4, NOTE_E4,
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2 };

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone (8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay (pauseBetweenNotes);
    // stop the tone playing:
    noTone (8);
  }
  
  // Now go to sleep until a reset
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  ADCSRA |= (0<<ADEN);                     // disable ADC
  sleep_enable ();
  sleep_mode();
}

void loop() {
  // no need to repeat the melody.
}
