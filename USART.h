/*
 * USART.h
 *
 * Created: 27-05-2021 10:16:12 AM
 *  Author: Kunal
 */ 

#ifndef BAUD 
#define BAUD 2400
#endif

#define USART_HAS_DATA bit_is_set(UCSR0A, RXC0)
#define USART_READY    bit_is_set(UCSR0A, UDRE0)

void initUSART(void);
/* Takes the defined BAUD and F_CPU,
   calculates the bit-clock multiplier,
   and configures the hardware USART     */

void transmitByte(uint8_t data);
uint8_t receiveByte(void);
/*  Blocking transmit and recieve functions
    When we call receiveByte() our program will
	hang until data comes through.               */

void printString(const char myString[]);
/*  Utility function to transmit an entire string from the RAM  */

void  readString(char myString[], uint8_t maxLength);
/*  Define a string variable, pass it to this function 
    The string will contain whatever you typed over serial */

void printByte(uint8_t byte);
/*  prints a byte out as its 3-digit ascii equivalent */

void printWord(uint16_t word);
/*  Print a word out as its 5-digit ascii equivalent */

void printBinaryByte(uint8_t byte);
/*  Print a byte out in 1s and 0s */

char nibbleToHex(uint8_t nibble);
char nibbleToHexCharacter(uint8_t nibble);
void printHexByte(uint8_t byte);
/*  Print a byte out in hexadecimal */

uint8_t getNumber(void);
/*  Takes in up to three ascii digits,
    converts them to a byte when press enter  */

 
