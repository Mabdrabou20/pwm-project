/*
 * DIO.h
 *
 * Created: 9/23/2022 9:48:07 PM
 *  Author: Mr-X
 */ 


#ifndef DIO_H_
#define DIO_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "./BIT_MATH.h"

void SETPin_Output(unsigned char Port,unsigned char PinNumber);

void SETPin_Input(unsigned char Port,unsigned char PinNumber);

void Clear_Pin(unsigned char Port,unsigned char PinNumber);	
		
void Set_Pin(unsigned char Port,unsigned char PinNumber);

void Filp_Pin(unsigned char Port,unsigned char PinNumber);
	
unsigned char pin_read(unsigned char Port,unsigned char PinNumber);



#endif /* DIO_H_ */