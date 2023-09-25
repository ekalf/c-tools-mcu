/*
  delay_t.h
  
  Non-blocking delay functions
  for use with Arduino

  By R. Haenggi
  dev@svac.ch
  December 2018
*/


#ifndef __delay_t_h_INCLUDED__   // if delay_t.h hasn't been included yet...
#define __delay_t_h_INCLUDED__   // #define this so the compiler knows it has been included

// include necessary files
#include <stdint.h>
#include <Arduino.h>

class delay_t {

    public: 
        /*
        Constructor.
        */
        delay_t(void);

        /* starts a new delay */
        void delayStart( uint32_t duration_ms ) ;

        /* checks if delay duration has been reached */
        bool delayElapsed( void ) ;


    private:
        // private "global" variables
        uint32_t startMillis;
        uint32_t currentMillis;
        uint32_t duration;

};
#endif // __delay_t_h_INCLUDED__    if delay_t.h hasn't been included yet...