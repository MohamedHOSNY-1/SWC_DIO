/*
 * main.c
 *
 *  Created on: Aug 18, 2018
 *      Author: HOSNY
 */

#include "avr/io.h"
#include "LIB/BIT_MATH.h"
#include "avr/delay.h"
void main(void)
{
	/* Set PORTD as OUTPUT */
	DDRD = 0xFF;

	CLR_BIT(DDRA,0);

	SET_BIT(PORTA,0);

	while(1)
	{
		if(GET_BIT(PINA,0) == 0)
		{
			PORTD = ~PORTD;
		}
		else
		{
			PORTD = 0x00;
		}
		_delay_ms(500);
	}

}
