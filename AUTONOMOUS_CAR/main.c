/*
 * AUTONOMOUS_CAR.c
 *
 * Created: 14/04/2023 01:48:57 PM
 * Author : Ahmed Elzayady
 */
#define F_CPU 1000000UL
#include <util/delay.h>
/*UITLES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
/*MCAL_LIB*/
#include "DIO_interface.h"
/*HAL_LIB*/
#include "LCD_interface.h"
#include "DCM_interface.h"
#include "SERVO_interface.h"
#include "ULTRASONIC_interface.h"

int main(void)

{
	DIO_SetPinDirection(DIO_GROUPD, DIO_PIN7, DIO_SET_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_GROUPA, DIO_PIN2, DIO_SET_PIN_OUTPUT);
	LCD_Init();
	SERVO_Init();
	DCM_Init();
	u16 distance = 0, RightDistance = 0, LeftDistance = 0;
	SERVO_90_Degree();
	_delay_ms(200);
	LCD_SetCursor(1, 0);
	LCD_SendString("Dir:");
	while (1)
	{
		distance = ULTRASONIC_CalcDistance();
		if (distance > 20)
		{
			DCM_MoveForward();
			_delay_ms(100);
			LCD_SetCursor(1, 5);
			LCD_SendString("FORW");
		}

		else
		{

			DCM_STOP();
			_delay_ms(100);
			LCD_SetCursor(1, 5);
			LCD_SendString("STOP");
			SERVO_0_Degree();
			_delay_ms(200);
			RightDistance = ULTRASONIC_CalcDistance();
			_delay_ms(100);
			SERVO_180_Degree();
			_delay_ms(200);
			LeftDistance = ULTRASONIC_CalcDistance();
			_delay_ms(100);
			if (RightDistance > LeftDistance)
			{
				DCM_MoveBack();
				_delay_ms(100);
				LCD_SetCursor(1,5);
				LCD_SendString("BACK");
				_delay_ms(100);
				DCM_MoveRight();
				_delay_ms(100);
				LCD_SetCursor(1, 5);
				LCD_SendString("Righ");
				_delay_ms(100);
				DCM_MoveForward();
			}
			else if (LeftDistance > RightDistance)
			{
				DCM_MoveBack();
				_delay_ms(100);
				LCD_SendString("BACK");
				_delay_ms(100);
				DCM_MoveLeft();
				_delay_ms(100);
				LCD_SetCursor(1, 5);
				LCD_SendString("Left");
				_delay_ms(100);
				DCM_MoveForward();
			}
		}
	}
}
