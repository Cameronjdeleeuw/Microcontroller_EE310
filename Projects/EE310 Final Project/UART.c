 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <time.h>
//#include "adc.h"

//#define _XTAL_FREQ 4000000
//#define FCY   _XTAL_FREQ/4
/*
    Main application
*/

#define Vref 5.0

int digital;
float voltage;
float result;
char data[10];
void ADC_Init(void);

void ADC_Init(void){
    ADCON0bits.FM = 1;
    ADCON0bits.CS = 1;
    
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSELA0 = 1;
    
    ADPCH = 0x00;
    ADCLK = 0x00;
    
    ADRESH = 0x00;
    ADRESL = 0x00;
    
    ADPREL = 0x00;
    ADPREH = 0x00;
    
    ADACQL = 0x00;
    ADACQH = 0x00;
    
    ADCON0bits.ON = 1;
}


int main(void)
{
    ADC_Init();
    SYSTEM_Initialize();
    UART2_Initialize();;

    while(1)
    {
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        
        digital = (ADRESH * 256) | (ADRESL);
        voltage = (digital * ((float)Vref/(float)(4096)));
        
        printf("%f\r\n", voltage);
        __delay_ms(1000);
        //PORTBbits.RB1 ^= 1;
    }    
}
