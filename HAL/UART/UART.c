/*
 * UART.c

 *
 *  Created on: Aug 11, 2016
 *      Author: ahmed
 */
#include "UART.h"

void UART_init(void)
 {
	UCSRB=(1<<RXEN)|(1<<TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=51;  // baud rate 9600 bit/sec
 }

void UART_send_byte( char byte)
 {
	while(!(UCSRA &(1<<UDRE))); // while shift register flag != 1 (not empty))
	UDR=byte;

 }

void UART_send_string( char *ptr)
 {
	int i=0;

		while(ptr[i] != '\0')
		 {
			UART_send_byte(ptr[i]);
			i++;
		 }
	UART_send_byte(ptr[i]);
 }

 char  UART_recieve_byte(void)
 {
	while((UCSRA & (1<<RXC)) ==0);

		return UDR ;


 }
void  UART_recieve_string(char * ptr)
 {
	int i=0;
	ptr[i]=UART_recieve_byte();
	while(ptr[i] !='#')
	 {
		i++;
		ptr[i]=UART_recieve_byte();

	 }
	ptr[i]='\0';


 }

