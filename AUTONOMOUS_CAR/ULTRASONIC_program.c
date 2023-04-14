#include "DIO_interface.h"
#include <avr/io.h>
#define  F_CPU 1000000UL
#include <util/delay.h>
u16 ULTRASONIC_CalcDistance()
{
u16 a,b,high,distance;
	TCCR1A = 0;
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
	DIO_SetPinValue(DIO_GROUPD,DIO_PIN7,HIGH);
	_delay_us(50);
	DIO_SetPinValue(DIO_GROUPD,DIO_PIN7,LOW);
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */
	high=b-a;
	distance=((high*34600)/(F_CPU*2)) ;
	return distance;
}