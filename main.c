/*
 * AMIT.c
 *
 * Created: 3/12/2023 10:11:46 PM
 * Author : Mega
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "DIO.h"
#include "../HAL/GLCD_interface.h"
#include "../HAL/LCD.h"
int main(void)
{
  //init lcd
  SETPin_Output(0,0);
  Set_Pin(0,0);
  H_LCD_INIT();
  
  //globle interrupt
 // SET_BIT(SREG,7);
  //set input
 // SETPin_Input(3,6);
  
  //init input capture unit 
     float duty_cycle=0;
	long frequency=0,time_total=0;
	int first_reading=0,second_reading=0,third_reading=0,tick_on=0,total_p=0;
    TCCR1A = 0;//timer at normal mode 
    TCNT1 = 0;//clear req of the counter
    TIFR = (1 << ICF1); // Clear Input Capture flag
	
    TCCR1B = 0x41; // Rising edge, no prescaler 
	//first
	 while ((TIFR & (1 << ICF1)) == 0);
	first_reading= ICR1;
	TIFR = (1 << ICF1); // Clear Input Capture flag
	TCCR1B = 0x01; // Falling edge, no prescaler 
    //second
	while ((TIFR & (1 << ICF1)) == 0);
    second_reading= ICR1; 
    TIFR = (1 << ICF1); // Clear ICF flag 
    TCCR1B = 0x41; // Rising edge, no prescaler 
    //third
    while ((TIFR & (1 << ICF1)) == 0);
    third_reading = ICR1; 
    TIFR = (1 << ICF1); // Clear ICF flag  can let the flag high

    TCCR1B = 0; // Stop the timer 

   // check reading
    if (first_reading < second_reading && second_reading < third_reading) 
	 {
        tick_on = second_reading - first_reading;
        total_p = third_reading - first_reading;

        frequency = F_CPU / total_p;// 1/(tick__all/16000000)
		
        time_total = 1000000 / frequency;//in micro
        
        duty_cycle = ( (float)tick_on /(float)total_p)*100;// Calculate duty cycle 
    } 
	else 
	{
		while(1)
        H_LCD_Writestring("erorr");
    }
  
  //line 1
  H_LCD_WriteCommands(0X80);
  H_LCD_Writestring("du=");
  H_LCD_GoTo_row_col(1,3);
  H_LCD_WriteNumber(duty_cycle);
  H_LCD_GoTo_row_col(1,5);
  H_LCD_Writestring("_____");
   H_LCD_GoTo_row_col(1,10);
  H_LCD_Writestring("fr=");
  H_LCD_GoTo_row_col(1,13);
  H_LCD_WriteNumber(frequency);
  
  
  //line 2
  H_LCD_WriteCommands(0XC0);
  H_LCD_Writestring("____|    ");
  H_LCD_GoTo_row_col(2,5);
  H_LCD_Writestring("t=");
   H_LCD_GoTo_row_col(2,7);
   H_LCD_WriteNumber(time_total);
   H_LCD_GoTo_row_col(2,11);
   H_LCD_Writestring("|____");
    while (1) 
    {
		
    }
}
