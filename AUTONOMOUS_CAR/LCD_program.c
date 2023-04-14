
#define F_CPU 16000000UL
#include <util/delay.h>

/*UITLES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
/*MCAL_LIB*/
#include "DIO_interface.h"
/*HAL_LIB*/
#include "LCD_interface.h"
#include "LCD_config.h"



/*Start LCD Function*/
void LCD_Init(void)
{
    // set pins directions for LCD
DIO_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_En_PORT,LCD_En_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_SET_PIN_OUTPUT);
DIO_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_SET_PIN_OUTPUT);

_delay_ms(35);
// set RS pin =0 (write a command)
DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
// set RW pin =0 (write)
DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
LCD_WriteHalfPort(0b0010);
/*Enable*/
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,LOW);
// Function Set Command 2*16 LCD || 4 Bit Mode
LCD_SendCmnd(0b00101000);
_delay_us(45);
LCD_SendCmnd(0b00001100); // Display Cursor On , Blinker On
_delay_us(45);
LCD_SendCmnd(0b00000001); //Clear
_delay_ms(2);
LCD_SendCmnd(0b00000110);
}
/*Send commands Function*/
void LCD_SendCmnd(u8 cmnd)
{

// set RS pin =0 (write a command)
DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);

// set RW pin =0 (write)
DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);

// Write The Most 4 bits Of Command On Data Pins
LCD_WriteHalfPort(cmnd>>4);

/*Enable*/
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,LOW);

// Write The Least 4 bits Of Command On Data Pins
LCD_WriteHalfPort(cmnd);

/*Enable*/
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,LOW);
}


/*Send char Function*/
void LCD_SendChar(u8 data)
{

// set RS pin =1 (Read Data)
DIO_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

// set RW pin =0 (write)
DIO_SetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);

// Write The Most 4 bits Of Data On Data Pins
LCD_WriteHalfPort(data>>4);

/*Enable*/
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,LOW);

// Write The Least 4 bits Of Data On Data Pins
LCD_WriteHalfPort(data);

/*Enable*/
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,HIGH);
_delay_ms(1);
DIO_SetPinValue(LCD_En_PORT,LCD_En_PIN,LOW);

}


/*WriteHalfPort Function*/
void LCD_WriteHalfPort(u8 value)
{
 
	if (CHK_BIT(value, 0) == 1)
	{
		DIO_SetPinValue(LCD_D4_PORT,LCD_D4_PIN, HIGH);
	}

	else
	{
		DIO_SetPinValue(LCD_D4_PORT,LCD_D4_PIN, LOW);
	}

	if (CHK_BIT(value, 1) == 1)
	{
		DIO_SetPinValue(LCD_D5_PORT,LCD_D5_PIN, HIGH);
	}

	else
	{
		DIO_SetPinValue(LCD_D5_PORT,LCD_D5_PIN, LOW);
	}
	if (CHK_BIT(value, 2) == 1)
	{
		DIO_SetPinValue(LCD_D6_PORT,LCD_D6_PIN, HIGH);
	}

	else
	{
		DIO_SetPinValue(LCD_D6_PORT,LCD_D6_PIN, LOW);
	}
	if (CHK_BIT(value, 3) == 1)
	{
		DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN, HIGH);
	}

	else
	{
		DIO_SetPinValue(LCD_D7_PORT,LCD_D7_PIN, LOW);
	}
}
void LCD_SendString(u8*String)
{

u8 StringLength=0;
while (String[StringLength] != '\0')
{
LCD_SendChar(String[StringLength]);
StringLength ++;

}
}

void LCD_Clear(void)
{
LCD_SendCmnd(0b00000001);
_delay_ms(2);
}

void LCD_writeNumber(u32 number)
{
 u32 Local_reversed = 1;
 if (number == 0)
 {
  LCD_SendChar('0');
 }
 else
 {
  // Reverse Number
  while (number != 0)
  {
   Local_reversed = Local_reversed*10 + (number%10);
   number /= 10;
  }
  
  do 
  {
   LCD_SendChar((Local_reversed%10)+'0');
   Local_reversed /= 10;
  }while (Local_reversed != 1);
 } 
}
void LCD_SetCursor(u8 LineNumber, u8 Position)
{
 if(LineNumber == LCD_LINE_ONE)
 {
  if(Position <= 15)
  {
   LCD_SendCmnd(0x80 + Position);
  }
 }

 else if (LineNumber == LCD_LINE_TWO)
 {
  if(Position <= 15)
  {
   LCD_SendCmnd(0xc0 + Position);
  }
 }
}
