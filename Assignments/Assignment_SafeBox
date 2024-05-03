//---------------------
// Title: Interfacing With Sensors
//---------------------
//Program Details: Use photo resistors to make a secret code that operates a motor when done correctly
// 
//-------	
// Purpose: To To expand knowledge on interfacing different components in C
//
// File Dependencies / Libraries: None 
// Compiler: XC8, v2.46
// Platform: MPLABX, v6.20
// Author: Antonino Balistreri
// Outputs: PORTD0,1,2,3,4,5,6,7
// Inputs: PORTB0,1,2,3,4,5,6,7 / PORTA0,1,2,3,4,5,6,7
// Date: APRIL 20, 2024
// Versions:
//       V1.0: 4/20/2024 - First Version


#include "config.h"
#include "functions.h"
#include "variables.h"
#include <xc.h>

#define _XTAL_FREQ 4000000
#define FCY     _XTAL_FREQ/4

//* Program Function Declaration *//
void restart();
void readphoto();
void emergency();
void display1();
void display2();
void compare();
void buzzer();

void main (void){
    TRISD = 0b00000000; LATD = 0; ANSELD = 0;
    PORTD = 0b00000000;
    TRISB = 0b00000001; LATB = 0; ANSELB = 0;
    PORTB = 0b00000000;
    TRISA = 0b00110000; LATA = 0; ANSELA = 0;
    PORTA = 0b00000000;
    interruptInitialize();
    
    while(1){
        readphoto();
        display1();
        display2();
        //compare();
    }
        
}
