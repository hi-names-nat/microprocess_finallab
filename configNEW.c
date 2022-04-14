
// ---------------------------------------------------------------------------
//
//      Source file containing the configuration subroutines
//
// ---------------------------------------------------------------------------

#include "config.h"

// Setup oscillator to 4MHz
void OSCILLATOR_Initialize(void) {
    // NOSC HFINTOSC; NDIV 4; 
    OSCCON1 = 0x60;
}

// Initialize the PORTS and the PPS
void PORT_PIN_Initialize(void) {
    
    LATA = 0x00;
    TRISA = 0x00;
    ANSELA = 0x00;
    
    LATB = 0x00;
    TRISB = 0b11110101;
    ANSELB = 0x00;
    
    LATC = 0x00;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC0 = 1;
    ANSELC = 0x00;
    
    LATD = 0x00;
    TRISD = 0x000;
    ANSELD = 0x00;

    // Unlock PPS
    PIE0bits.IOCIE = 0;
    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS
    
    // Assign UART pins
    RC1PPS = 0x0010;            //RC1->EUSART:TX;
    //RXPPSbits.RXPPS = 0x0010;   //RC0->EUSART:RX;
    RXPPS = 0x10;
    
    // Assign SPI pins
    SSP1CLKPPSbits.SSP1CLKPPS = 0x0013;   //RC3->MSSP1:SCK1;
    SSP1DATPPSbits.SSP1DATPPS = 0x000A;   //RB2->MSSP1:SDI1;
    RB3PPS = 0x0015;   //RB5->MSSP1:SDO1;
    RB1PPS = 0x0014;   //RB3->MSSP1:SCK1;
    
    // Lock PPS
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
}
