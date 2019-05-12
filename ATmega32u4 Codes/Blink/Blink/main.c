/*
 * Blink.c
 *
 * Created: 15-03-2019 15:34:07
 * Author : Chirag
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//ensure PE2 is input
	//Never make PE2 output since it is required for hwb
	
	DDRE &= ~(1 << DDE2);  
	//PORTE |= (1 << 2);	//enable pullup
	
	DDRC |= (1 << DDC6);
	DDRE |= (1 << DDE6);
	
    /* Replace with your application code */
    while (1) 
    {
		PORTC &= ~(1 << 6);
		PORTE &= ~(1 << 6);
		_delay_ms(1000);
		
		PORTC |= (1 << 6);
		PORTE &= ~(1 << 6);
		_delay_ms(1000);
		
		//PORTE &= ~(1 << 2);
		PORTC &= ~(1 << 6);
		PORTE |= (1 << 6);
		_delay_ms(1000);
		
		PORTC |= (1 << 6);
		PORTE |= (1 << 6);
		_delay_ms(1000);
    }
}

