/* 
 *  lab4code.c
 * 
 *  Copyright (c) 2017 - OU-Maarten Uijt de Haag
 * 
 */

// Insert subroutines
struct LightStatus
{
    bool RA4, RA5, RA6;
};

int8_t patternLength = 10;
LightStatus* selectedPattern, pattern1[10], pattern2[10], pattern3[10], sSegOuter = true;

#include "config.h"
#include "serial_uart.h"




// Subroutine that transmits the Menu to the PC
void Build_Menu() {

    putch(0x0c);
    printf("\r\n\r\n\tMain Menu\r\n\r\n\r\n");
    printf("\tf\tFirst Name\r\n\r\n");
    printf("\tl\tLast Name\r\n\r\n");
    printf("\t4\tSend Pattern 1 to RA4, RA5, and RA6\r\n\r\n");
    printf("\t5\tSend Pattern 2 to RA4, RA5, and RA6\r\n\r\n");
    printf("\t6\tSend Pattern 3 to RA4, RA5, and RA6\r\n\r\n");
    printf("\ti\tMake the internal elements of the 7 segment LEDs flash at 0.5 second intervals.\r\n\r\n");
    printf("\to\tMake the external elements of the 7 segment LEDs flash at 0.5 second intervals.\r\n\r\n");
    printf("\tm\tMenu\r\n\r\n");
    
}

// Interrupt Service Routine (ISR))
void interrupt my_isr(void) {

    int8_t c;
    
    if( RCIE && RCIF) {
        
        // Get character
        c = getch();
        
        // Check what character was received and act on it
        switch(c) {
            
            case 'f':   printf("Natalie\r\n"); break;
            case 'l':   printf("Soltis\r\n"); break;
            case 'm':   Build_Menu(); break;
            case '4':   selectedPattern = &pattern1; break;
            case '5':   selectedPattern = &pattern2; break;
            case '6':   selectedPattern = &pattern3; break;
            case 'i':   sSegOuter = false; break;
            case 'o':   sSegOuter = true; break;
        }
    }
        
}

// Main program
int main(int argc, char** argv) 
{
    // Local variables
    int cnt;
    
    // Setup the oscillator
    OSCILLATOR_Initialize();
    
    // Initialize PPS and PORTS
    PORT_PIN_Initialize();
    
    // Initialize the UART
    UART_Initialize();
    
    // Draw the menu
    Build_Menu();
    
    while (1)
    {
       
    }
}