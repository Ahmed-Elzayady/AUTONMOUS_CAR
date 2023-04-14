
/*
 * DCM_program.c
 *
 * Created: 14/04/2023 02:35:26 ص
 *  Author: Ahmed Elzayady
 */ 

#include "DIO_interface.h"
#include "DCM_config.h"
void DCM_Init()
{
		DIO_SetPinDirection(DCM_PORT,DCM_PIN0,DIO_SET_PIN_OUTPUT);
		DIO_SetPinDirection(DCM_PORT,DCM_PIN1,DIO_SET_PIN_OUTPUT);
		DIO_SetPinDirection(DCM_PORT,DCM_PIN2,DIO_SET_PIN_OUTPUT);
		DIO_SetPinDirection(DCM_PORT,DCM_PIN3,DIO_SET_PIN_OUTPUT);
}
void DCM_MoveForward()
{
	
		DIO_SetPinValue(DCM_PORT,DCM_PIN0,HIGH);
		DIO_SetPinValue(DCM_PORT,DCM_PIN1,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN2,HIGH);
		DIO_SetPinValue(DCM_PORT,DCM_PIN3,LOW);
}
void DCM_MoveRight()
{
	
		DIO_SetPinValue(DCM_PORT,DCM_PIN0,HIGH);
		DIO_SetPinValue(DCM_PORT,DCM_PIN1,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN2,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN3,LOW);
}


void DCM_MoveLeft()
{
	
		DIO_SetPinValue(DCM_PORT,DCM_PIN0,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN1,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN2,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN3,HIGH);
}



void DCM_MoveBack()
{
	
		DIO_SetPinValue(DCM_PORT,DCM_PIN0,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN1,HIGH);
		DIO_SetPinValue(DCM_PORT,DCM_PIN2,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN3,HIGH);
}

void DCM_STOP()
{
		DIO_SetPinValue(DCM_PORT,DCM_PIN0,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN1,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN2,LOW);
		DIO_SetPinValue(DCM_PORT,DCM_PIN3,LOW);
}