//---------------------
// Title: EE310 Final Project
//---------------------
// Program Details: Using the timers to generate a frequency to activate a passive buzzer
// 	
// Purpose: To add a peripheral to our final project
//
// File Dependencies / Libraries: None 
// Compiler: XC8, v2.46
// Platform: MPLABX, v6.20
// Operating System: MACOSX, Windows 11
// Author(s): Antonino Balistreri, Cameron deLeeuw
// Outputs:  
// Inputs: 
// Date: MAY 11, 2024
// Versions:
//       V1.0: 5/11/2024 - First Version - Project Creation

#include <xc.h>
#include <finalHeader.h>

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

uint8_t checkTimerValue;
#define myBUZZ  PORTDbits.RD1

void main (void){
    
}
