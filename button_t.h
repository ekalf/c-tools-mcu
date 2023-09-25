/*
  button_t.h
  
  Non-blocking button/input parsing functions
  for use with Arduino

  By R. Haenggi
  dev@svac.ch
  January 2022
*/
#ifndef UBTN_H
#define UBTN_H

#include <Arduino.h>
#include <Adafruit_MotorShield.h>
#include "delay_t.h"

class button_t {
  private:
    bool invert_btn;
    bool last;
    uint8_t inputPin;
    uint8_t inputMode;
    delay_t debounce;
    uint16_t debounceDelay;
  public:
    bool changed;
    bool pressed;
    bool released;
    bool state;
    void update(void);
    button_t(uint8_t pin, uint8_t mode, uint16_t debounce_delay_ms);
};

#endif