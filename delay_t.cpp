/*
  delay_t.cpp
  
  Non-blocking delay functions
  for use with Arduino

  By R. Haenggi
  dev@svac.ch
  December 2018
*/

#include "delay_t.h"

/*
Constructor.
*/
delay_t::delay_t(void)
{   
    // set starting values for the variables
    startMillis = 0x0;
    currentMillis = 0x0;
    duration = 0xFFFFFFFF;

    return;
}

/* starts a new delay */
void delay_t::delayStart( uint32_t duration_ms ) 
{
    // current program time / time in millisecond since program has started. Overflow every 49.xx days.
    startMillis = millis();                         // set as starting value
    duration = duration_ms;
    return;
}

/* checks if delay duration has been reached */
bool delay_t::delayElapsed( void )
{
    // current program time / time in millisecond since program has started. Overflow every 49.xx days.
    currentMillis = millis();
    if (currentMillis - startMillis >= duration)    // has enough time passed?
        return(true);                               // aye
    else
        return(false);                              // no
}