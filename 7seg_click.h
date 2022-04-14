
#include <xc.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

extern uint8_t GetCode(uint8_t dig); 

// Subroutine that transmits the Menu to the PC
extern void Build_Menu();

extern void Reset7SegDevice();

extern void WriteNumbers7Seg(uint8_t num2, uint8_t num1);
extern void WriteNumbers7SegMSDDot(int8_t num2, int8_t num1);