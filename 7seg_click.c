
#include "config.h"
#include "serial_uart.h"
#include "serial_spi.h"
#include "7seg_click.h"

uint8_t GetCode(uint8_t dig) {
    
    switch(dig)
    {
        case 0: return(0b01111110); 
        case 1: return(0b00001010); 
        case 2: return(0b10110110); 
        case 3: return(0b10011110); 
        case 4: return(0b11001010); 
        case 5: return(0b11011100); 
        case 6: return(0b11111000); 
        case 7: return(0b00001110); 
        case 8: return(0b11111110); 
        case 9: return(0b11011110); 
        default: return(0); 
    }
   
}

// Subroutine that transmits the Menu to the PC
void Build_Menu() {

    putch(0x0c);
    printf("\r\n\r\n\tMain Menu\r\n\r\n\r\n");
    printf("\tf\tFirst Name\r\n\r\n");
    printf("\tl\tLast Name\r\n\r\n");
    printf("\t4\tToggle LED on RA4\r\n\r\n");
    printf("\t5\tToggle LED on RA5\r\n\r\n");
    printf("\t6\tToggle LED on RA6\r\n\r\n");
    printf("\tr\tRequest voltage\r\n\r\n");
    printf("\tm\tMenu\r\n\r\n");
    

}

void Reset7SegDevice() {
     RD0 = 0;
    __delay_ms(10);
    RD0 = 1;
}

void WriteNumbers7Seg(uint8_t num2, uint8_t num1) {
    
    uint8_t a;
    
    a = GetCode(num1);
    SPI1_Write(a);
    a = GetCode(num2);
    SPI1_Write(a);
    RA3 = 0;
    __delay_ms(10);
    RA3 = 1;
}

void WriteNumbers7SegMSDDot(int8_t num2, int8_t num1) {
    
    int8_t a;
    
    // Get code and write the most significant digit
    a = GetCode(num1);
    SPI1_Write(a);
    
    // Get code and write the least significant digit
    a = GetCode(num2);
    
    // INsert the 'dot'
    a = a | 0b00000001;
    
    SPI1_Write(a);
    
    // Latch
    RA3 = 0;
    __delay_ms(10);
    RA3 = 1;
}

