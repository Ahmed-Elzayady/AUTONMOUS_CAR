/*
 * SERVO_program.c
 *
 * Created: 12/04/2023 07:55:26 PM
 *  Author: Ahmed Elzayady
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <avr/io.h>
#include "DIO_interface.h"
#include "SERVO_interface.h"
#include <util/delay.h>
void SERVO_Init(void)
{
	DIO_SetPinDirection(DIO_GROUPC,DIO_PIN0,DIO_SET_PIN_OUTPUT);
	DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,LOW);
}
void SERVO_0_Degree(void)
{
	
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,HIGH);
		_delay_us(1000);
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,LOW);
}

void SERVO_90_Degree(void)
{
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,HIGH);
		_delay_us(1500);
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,LOW);
}
void SERVO_180_Degree(void)
{
	
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,HIGH);
		_delay_us(2000);
		DIO_SetPinValue(DIO_GROUPC,DIO_PIN0,LOW);
}