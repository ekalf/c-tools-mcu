/*
  button_t.h
  
  Non-blocking button/input parsing functions
  for use with Arduino

  By R. Haenggi
  dev@svac.ch
  January 2022
*/
#include "button_t.h"



using namespace std;
#define low false
#define high true

button_t::button_t(uint8_t pin, uint8_t mode, uint16_t debounce_delay_ms) {
  this->inputPin = pin;
  this->inputMode = mode;
  this->debounceDelay = debounce_delay_ms;
  if( this->inputMode = INPUT_PULLUP )
    this->invert_btn = true;
  pinMode(this->inputPin, this->inputMode);
  debounce.delayStart(0);
}

void button_t::update(void) {
 
    if( digitalRead(inputPin) == (invert_btn ? low : high) ) {
      this->state = true;
      if( this->last == false && debounce.delayElapsed() ) {
        this->changed = true;
        this->pressed = true;
        this->released = false;
        debounce.delayStart(this->debounceDelay);
      } else {
        this->changed = false;
        this->pressed = false;
        this->released = false;
      }
      this->last = true;
    } else {
      this->state = false;
      if( this->last == true && debounce.delayElapsed()) {
        this->changed = true;
        this->pressed = false;
        this->released = true;
        debounce.delayStart(this->debounceDelay);
      } else {
        this->changed = false;
        this->pressed = false;
        this->released = false;
      }
      this->last = false;
    }

  
  return;
}