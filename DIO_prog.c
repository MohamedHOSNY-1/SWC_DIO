/*
 * DIO_prog.c
 *
 *  Created on: Aug 18, 2018
 *      Author: HOSNY
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_reg.h"

volatile u8* DIO_OutRegsArr[4] = {PORTA_Reg,PORTB_Reg,PORTC_Reg,PORTD_Reg};
volatile u8* DIO_InRegsArr [4] = {PINA_Reg,PINB_Reg,PINC_Reg,PIND_Reg};
volatile u8* DIO_DirRegsArr[4] = {DDRA_Reg,DDRB_Reg,DDRC_Reg,DDRD_Reg};

void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
	if((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if(u8PinValCopy == HIGH)
		{
			SET_BIT((*DIO_OutRegsArr[u8PortIdCopy]),u8PinIdCopy);
		}
		else if(u8PinValCopy == LOW)
		{
			CLR_BIT(*DIO_OutRegsArr[u8PortIdCopy],u8PinIdCopy);
		}
		else
		{

		}
	}
	else
	{

	}
}

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	if((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		return(GET_BIT((*DIO_InRegsArr[u8PortIdCopy]),u8PinIdCopy));
	}
	else
	{
		return 0xFF;
	}
}

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	if((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if(u8PinDirCopy == OUTPUT)
		{
			SET_BIT(*DIO_DirRegsArr[u8PortIdCopy],u8PinIdCopy);
		}
		else if(u8PinDirCopy == INPUT)
		{
			CLR_BIT(*DIO_DirRegsArr[u8PortIdCopy],u8PinIdCopy);
		}
		else
		{

		}
	}
	else
	{

	}
}

void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	if(u8PortId <= PORTD)
	{
		if(u8PortDir == INPUT || u8PortDir == OUTPUT)
		{
			*DIO_DirRegsArr[u8PortId] = u8PortDir;
		}
		else
		{

		}
	}
	else
	{

	}
}

void DIO_SetPortValue(u8 u8PortId, u8 u8PortVal)
{
	if(u8PortId <= PORTD)
	{
			*DIO_OutRegsArr[u8PortId] = u8PortVal;
	}
	else
	{

	}
}
