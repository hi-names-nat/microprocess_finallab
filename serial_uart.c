
#include "serial_uart.h"

// Initialization of the UART
void UART_Initialize(void) {
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD1CON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RC1STA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX1STA = 0x24;

    // Baud Rate = 19200; SP1BRGL 12; 
    SP1BRGL = 51;

    // Baud Rate = 19200; SP1BRGH 0; 
    SP1BRGH = 0x00;
    
    // Initialize the receive interrupt service
    RCIE = 1;
    GIE = 1;
    PEIE = 1;

}

// Read from the UART
uint8_t UART_Read(void) {

    while(!PIR3bits.RCIF)
    {
    }

    if(1 == RC1STAbits.OERR)
    {
        // EUSART error - restart

        RC1STAbits.CREN = 0; 
        RC1STAbits.CREN = 1; 
    }

    return RC1REG;
}

// Write to UART
void UART_Write(uint8_t txData) {
    while(0 == PIR3bits.TXIF)
    {
    }

    TX1REG = txData;    // Write the data byte to the USART.
}

// Overload 'getch' function
char getch(void) {
    return UART_Read();
}

// Overload 'putch' function
void putch(char txData) {
    UART_Write(txData);
}

