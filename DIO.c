/*
 * DIO.c
 *
 * Created: 9/23/2022 9:48:53 PM
 *  Author: Mr-X
 */ 

#include "DIO.h"

void SETPin_Output(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		DDRA= DDRA |1<<PinNumber;
		break;
		case 1:
		DDRB= DDRB |1<<PinNumber;
		break;
		case 2:
		DDRC= DDRC |1<<PinNumber;
		break;
		case 3:
		DDRD= DDRD |1<<PinNumber;
		break;
		default:
	
		break;
	}
	
	
}



void SETPin_Input(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		DDRA =DDRA &(~(1<<PinNumber));
		break;
		case 1:
		DDRB =DDRB &(~(1<<PinNumber));
		break;
		case 2:
		DDRC =DDRC &(~(1<<PinNumber));
		break;
		case 3:
		DDRD =DDRD &(~(1<<PinNumber));
		break;
		default:
		break;
	}
}

void Clear_Pin(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		PORTA =PORTA &(~(1<<PinNumber));
		break;
		case 1:
		PORTB =PORTB &(~(1<<PinNumber));
		break;
		case 2:
		PORTC =PORTC &(~(1<<PinNumber));
		break;
		case 3:
		PORTD =PORTD &(~(1<<PinNumber));
		break;
		default:
		break;
	}
}

void Set_Pin(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		PORTA= PORTA |1<<PinNumber;
		break;
		case 1:
		PORTB= PORTB |1<<PinNumber;
		break;
		case 2:
		PORTC= PORTC |1<<PinNumber;
		break;
		case 3:
		PORTD= PORTD |1<<PinNumber;
		break;
		default:
		break;
	}
}
void Filp_Pin(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		PORTA= PORTA ^1<<PinNumber;
		break;
		case 1:
		PORTB= PORTB ^1<<PinNumber;
		break;
		case 2:
		PORTC= PORTC ^1<<PinNumber;
		break;
		case 3:
		PORTD= PORTD ^1<<PinNumber;
		break;
		default:
		break;
	}
}



unsigned char pin_read(unsigned char Port,unsigned char PinNumber)
{
	switch (Port)
	{
		case 0:
		GET_BIT(PINA,PinNumber);
		break;
		case 1:
		GET_BIT(PINB,PinNumber);
		break;
		case 2:
		GET_BIT(PINC,PinNumber);
		break;
		case 3:
		GET_BIT(PIND,PinNumber);
		break;
		default:
		break;}}