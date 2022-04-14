

#include <xc.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Initialization of the UART
extern void UART_Initialize(void);

// Read from the UART
extern uint8_t UART_Read(void);

// Write to UART
extern void UART_Write(uint8_t txData);

// Overload 'getch' function
extern char getch(void);

// Overload 'putch' function
extern void putch(char txData);

