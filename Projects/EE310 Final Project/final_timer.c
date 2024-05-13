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
#include "finalHeader.h"

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

uint8_t checkTimerValue;
//#define myBUZZ  PORTBbits.RB4
//
//void TMR0_Initialize(void)
//{
//    // Set TMR0 to the options selected in the User Interface
//
//    // T0CS FOSC/4; T0CKPS 1:256; T0ASYNC synchronised; 
//    T0CON1 = 0x48;
//
//    // TMR0H ;  The total division will be (FOSC/4)/(4+1)x256)))
//    TMR0H = 0x27; 
//
//    // TMR0L 0; 
//    TMR0L = 0x00;
//
//    // Clear Interrupt flag before enabling the interrupt
//    PIR3bits.TMR0IF = 0;
//
//    // Enabling TMR0 interrupt.
//    PIE3bits.TMR0IE = 1;
//
//    // T0OUTPS 1:1; T0EN enabled; T016BIT 8-bit; 
//    T0CON0 = 0x80;
//}
//
//void TMR0_StartTimer(void)
//{
//    // Start the Timer by writing to TMR0ON bit
//    T0CON0bits.T0EN = 1;
//}
//
//void TMR0_StopTimer(void)
//{
//    // Stop the Timer by writing to TMR0ON bit
//    T0CON0bits.T0EN = 0;
//}
//
//uint8_t TMR0_ReadTimer(void)
//{
//    uint8_t readVal;
//
//    // read Timer0, low register only
//    readVal = TMR0L;
//
//    return readVal;
//}
//
//void TMR0_WriteTimer(uint8_t timerVal)
//{
//    // Write to Timer0 registers, low register only
//    TMR0L = timerVal;
// }
//
//void TMR0_Reload(uint8_t periodVal)
//{
//   // Write to Timer0 registers, high register only
//   TMR0H = periodVal;
//}
//
//void __interrupt(irq(IRQ_TMR0), base(0x4008)) TMR0_ISR(void)
//{
//    T0CON0=0x00; // stop the timer & do what you have to do
//    TMR0L=0; // reset the timer
//    PIR3bits.TMR0IF = 0; // Clear the interrupt flag
//    myBUZZ ^= 1; // ISR code goes here
//    T0CON0=0x80; //start the timer
//    
//}
//void __interrupt(irq(default), base(0x4008)) DEFAULT_ISR(void)
//{
//// Unhandled interrupts go here
//}
//void INTERRUPT_Initialize (void)
//{
//INTCON0bits.GIEH = 1; // Enable high priority interrupts
//INTCON0bits.GIEL = 1; // Enable low priority interrupts
//INTCON0bits.IPEN = 1; // Enable interrupt priority
//
//PIE3bits.TMR0IE = 1; // Enable TMR0 interrupt
//PIE4bits.TMR1IE = 1; // Enable TMR1 interrupt
//
//IPR3bits.TMR0IP = 0; // Make TMR0 interrupt low priority
//// Change IVTBASE if required
//IVTBASEU = 0x00; // Optional
//IVTBASEH = 0x40; // Default is 0x0008
//IVTBASEL = 0x08;
//}

void main (void){
    ANSELB = 0b00000000;
    TRISB = 0b00000000;
    PORTB = 0b00000000;
//    INTERRUPT_Initialize();
//    TMR0_Initialize();
//    TMR0_StartTimer();
    
    while(1){
        for(int j=1;j<=3;j++)
            {
                //wait++;
                for(int u=0;u<=100;u++) // ma
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // ry
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // had
                {
                PORTB = 0b00010000;
                __delay_ms(1.911);
                PORTB = 0;
                __delay_ms(1.911);
                }
                for(int u=0;u<=100;u++) // a
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // lit
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // tle
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // lamb
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // lit
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // tle
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // lamb
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // lit
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // tle
                {
                PORTB = 0b00010000;
                __delay_ms(1.276);
                PORTB = 0;
                __delay_ms(1.276);
                }
                for(int u=0;u<=100;u++) // lamb
                {
                PORTB = 0b00010000;
                __delay_ms(1.276);
                PORTB = 0;
                __delay_ms(1.276);
                }
                for(int u=0;u<=100;u++) // ma
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // ry
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // had
                {
                PORTB = 0b00010000;
                __delay_ms(1.911);
                PORTB = 0;
                __delay_ms(1.911);
                }
                for(int u=0;u<=100;u++) // a
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // lit
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // tle
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                //__delay_ms(100);
                for(int u=0;u<=100;u++) // lamb
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // his
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // fleece
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // was
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=100;u++) // white
                {
                PORTB = 0b00010000;
                __delay_ms(1.517);
                PORTB = 0;
                __delay_ms(1.517);
                }
                for(int u=0;u<=100;u++) // as
                {
                PORTB = 0b00010000;
                __delay_ms(1.703);
                PORTB = 0;
                __delay_ms(1.703);
                }
                for(int u=0;u<=200;u++) // snow
                {
                PORTB = 0b00010000;
                __delay_ms(1.911);
                PORTB = 0;
                __delay_ms(1.911);
                }
        }
    }
}

