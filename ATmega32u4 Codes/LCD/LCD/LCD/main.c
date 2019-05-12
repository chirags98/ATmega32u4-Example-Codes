/*
 * LCD.c
 *
 * Created: 12-05-2019 14:09:58
 * Author : Chirag
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <avr/interrupt.h>

#define sbit(reg,bit)	reg |= (1<<bit)			// Macro defined for Setting a bit of any register.
#define cbit(reg,bit)	reg &= ~(1<<bit)		// Macro defined for Clearing a bit of any register.

void port_config (void)
{
	lcd_port_config();
}

void init_devices (void)
{
	cli(); //Clears the global interrupts
	lcd_start();
	sei();   //Enables the global interrupts
}

int main(void)
{	
	/*
	DDRF = 0b11111111;
	
	while (1)
	{
		PORTF = 0b11111111;
		_delay_ms(1000);
		PORTF = 0;
		_delay_ms(1000);
	}
	*/
	
	port_config();
	init_devices();
	
	lcd_string2(1, 1, "Hello World");	
	
    /* Replace with your application code */
    while (1) 
    {	
    }
}

