/* 
 *  lab4code.c
 * 
 *  Copyright (c) 2017 - OU-Maarten Uijt de Haag
 * 
 */

#include "config.h"
#include "serial_uart.h"

// Insert subroutines


// Subroutine that transmits the Menu to the PC
void Build_Menu() {

    putch(0x0c);
    printf("\r\n\r\n\tMain Menu\r\n\r\n\r\n");
    printf("\tf\tFirst Name\r\n\r\n");
    printf("\tl\tLast Name\r\n\r\n");
    printf("\t4\tToggle LED on RA4\r\n\r\n");
    printf("\t5\tToggle LED on RA5\r\n\r\n");
    printf("\t6\tToggle LED on RA6\r\n\r\n");
    printf("\tm\tMenu\r\n\r\n");
    
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