



void readphoto(){
        if(PORTA == 0b00010000){
            __delay_ms(100);
            pR1++;
            __delay_ms(250);
            
            while(PORTAbits.RA4 == 1){
                PORTDbits.RD7 = 1;
            }
            
        }
        if(PORTA == 0b00100000){
            __delay_ms(100);
            pR2++;
            __delay_ms(250);
            
            while(PORTAbits.RA5 == 1){
                PORTDbits.RD7 = 1;
            }
    }
        return;
}

void display1(){
    PORTD = 0x00;
    if(pR1 == 1){
        PORTD = 0x06;
    }
    if(pR1 == 2){
        PORTD = 0x5B;
    }
    if(pR1 == 3){
        PORTD = 0x4F;
    }
    if(pR1 == 4){
//       PORTB = 0b00010000;
//       PORTD = 0x00;
//       __delay_ms(500);
//       PORTB = 0b00000000;
       buzzer();
    }
    else{
        compare();
    }
    return;
}

void display2(){
    PORTD = 0x00;
    if(pR2 == 1){
        PORTD = 0x06;
    }
    if(pR2 == 2){
        PORTD = 0x5B;
    }
    if(pR2 == 3){
        PORTD = 0x4F;
    }
    if(pR2 == 4){
//       PORTB = 0b00010000;
//       PORTD = 0x00;
//       __delay_ms(500);
//       PORTB = 0b00000000;
       buzzer();
    }
    else{
        compare();
    }
    return;
}

void compare(){
    if(pR1 * 16 + pR2 == secretcode){
        PORTB = 0b00100000;
        __delay_ms(1000);
        PORTB = 0b00000000;
        __delay_ms(1000);
        restart();
    }
    //else{
        //readphoto();
    //}
    return;
}

//emergency interrupt
void __interrupt(irq(IRQ_INT0),base(0x4008)) INT0_ISR(void){ // Defining Interrupt ISR 

    if(PIR1bits.INT0IF == 1)
    { // Check if interrupt flag for INT0 is set to 1 - (note INT0 is your input)
        __delay_ms(250);
        for(int m = 0; m < 5; m++)
        {   // if so, do something
            PORTBbits.RB4 = 1;  // e.g,blink a buzzer connected to  PORTAbits.RA6 for 5 times with a delay of __delay_ms(250)
           __delay_ms(500);
           PORTBbits.RB4 = 0;
           __delay_ms(500);
        }
    }
        PIR1bits.INT0IF = 0;           // always clear the interrupt flag for INT0 when done               
        //PORTDbits.RD7 = 0;        // turn off the buzzer on PORTAbits.RA5 
}
void interruptInitialize (void){
    INTCON0bits.IPEN = 1; // Enable interrupt priority bit in INTCON0 (check INTCON0 register and find the bit)
    INTCON0bits.GIEH = 1; // Enable high priority interrupts using bits in INTCON0
    INTCON0bits.GIEL = 1; // Enable low priority interrupts using bits in INTCON0
    INTCON0bits.INT0EDG = 1; // Interrupt on rising edge of INT0 pin using bits in INTCON0
    IPR1bits.INT0IP = 1;  // Set the interrupt high priority (IP) for INT0 - INT0IP
    PIE1bits.INT0IE = 1; // Enable the interrupt (IE) for INT0

    PIR1bits.INT0IF = 0;   //Clear interrupt flag for INT01
  
    // Change IVTBASE by doing the following
    IVTBASEU = 0x00;  // Set IVTBASEU to 0x00 
    IVTBASEH = 0x40; // Set IVTBASEH to  0x40; 
    IVTBASEL = 0x08; // Set IVTBASEL to 0x08; 
}

void buzzer(){
    PORTB = 0b00010000;
    __delay_ms(300);
    PORTB = 0b00000000;
    __delay_ms(300);
    PORTB = 0b00010000;
    __delay_ms(300);
    PORTB = 0b00000000;
    __delay_ms(300);
    PORTB = 0b00010000;
    __delay_ms(300);
    PORTB = 0b00000000;
    restart();
}

void restart(){
    pR1 = 0;
    pR2 = 0;
    return;
}
