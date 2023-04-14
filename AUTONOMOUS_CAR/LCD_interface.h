/*
 * LCD_interface.h
 *
 *  Created on: 7/3/2023
 *      Author: Ahmed Elzayady
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_Init(void);
void LCD_SendCmnd(u8 cmnd);
void LCD_SendChar(u8 data);
void LCD_WriteHalfPort(u8 value);
void LCD_SendString(u8*String);
void LCD_Clear(void);
void LCD_writeNumber(u32 number);
void LCD_SetCursor(u8 LineNumber, u8 Position);
#endif /* LCD_INTERFACE_H_ */
