/*
 * USART.c
 *
 * Created: 27-05-2021 11:33:35 AM
 *  Author: Kunal
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include "USART.h"
#include <util/setbaud.h>

void initUSART(void) {
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#if USE_2X
	UCSR0A |=(1<<U2X0);
#else
	UCSR0A &=(1<<U2X0);
#endif

	/* Enable USART Transmitter and receiver  */
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	/* Character Size  8 data bits and 1 stop bit  */
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
 
}

void transmitByte(uint8_t data) {
	/* Wait for empty transmit buffer  */
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;      // send data
}

uint8_t receiveByte(void) {
	/*wait for incoming data   */
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;     // return register value 
	
}

void printString(const char myString[]) {
	uint8_t i =0;
	while(myString[i]) {
		transmitByte(myString[i]);
		i++;
	}
}

void readString(char myString[], uint8_t maxLength) {
	char response;
	uint8_t i=0;
	while (i<(maxLength-1)) {      // prevent over-run 
		response= receiveByte();   
		transmitByte(response);   // echo
		if (response=='/r') {     //enter marks the end
			break;
		}
		else {
			myString[i] = response;
			i++;
			}
	}
	myString[i] = 0;           //terminal null character
}

void printByte(uint8_t byte) {
	/*  Convert a byte to a string of decimal text, sends it */
	transmitByte('0' + (byte/100));  //Hundred
	transmitByte('0' + ((byte/10)%10)); //tens
	transmitByte('0' + (byte%10));
}

void printWord(uint16_t word) {
	transmitByte('0' + (word / 10000));                 /* Ten-thousands */
	transmitByte('0' + ((word / 1000) % 10));               /* Thousands */
	transmitByte('0' + ((word / 100) % 10));                 /* Hundreds */
	transmitByte('0' + ((word / 10) % 10));                      /* Tens */
	transmitByte('0' + (word % 10));                             /* Ones */
}

void printBinaryByte(uint8_t byte) {
	/* Prints out a byte as a series of 1's and 0's */
	uint8_t bit;
	for (bit = 7; bit < 255; bit--) {
		if (byte & (1<<bit))
		transmitByte('1');
		else
		transmitByte('0');
	}
}

char nibbleToHexCharacter(uint8_t nibble) {
	/* Converts 4 bits into hexadecimal */
	if (nibble < 10) {
		return ('0' + nibble);
	}
	else {
		return ('A' + nibble - 10);
	}
}

void printHexByte(uint8_t byte) {
	/* Prints a byte as its hexadecimal equivalent */
	uint8_t nibble;
	nibble = (byte & 0b11110000) >> 4;
	transmitByte(nibbleToHexCharacter(nibble));
	nibble = byte & 0b00001111;
	transmitByte(nibbleToHexCharacter(nibble));
}

uint8_t getNumber(void) {
	// Gets a numerical 0-255 from the serial port.
	// Converts from string to number.
	char hundreds = '0';
	char tens = '0';
	char ones = '0';
	char thisChar = '0';
	do {                                                   /* shift over */
		hundreds = tens;
		tens = ones;
		ones = thisChar;
		thisChar = receiveByte();                   /* get a new character */
		transmitByte(thisChar);                                    /* echo */
		} while (thisChar != '\r');                     /* until type return */
		return (100 * (hundreds - '0') + 10 * (tens - '0') + ones - '0');
	}
