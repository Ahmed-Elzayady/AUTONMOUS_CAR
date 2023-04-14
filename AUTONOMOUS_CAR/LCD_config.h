/*
 * LCD_config.h
 *
 *  Created on: 7/3/2023
 *      Author: Ahmed Elzayady
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Macros For RS configuration*/
#define LCD_RS_PORT              DIO_GROUPB
#define LCD_RS_PIN               DIO_PIN2
/*Macros For RW Configuration*/
#define LCD_RW_PORT              DIO_GROUPB
#define LCD_RW_PIN               DIO_PIN3
/*Macros For EN Configuration*/
#define LCD_En_PORT              DIO_GROUPB
#define LCD_En_PIN               DIO_PIN1
/*Macros For 4 Bits Mode Pins Configurations*/

#define LCD_D4_PORT              DIO_GROUPA
#define LCD_D4_PIN               DIO_PIN4

#define LCD_D5_PORT              DIO_GROUPA
#define LCD_D5_PIN               DIO_PIN5

#define LCD_D6_PORT              DIO_GROUPA
#define LCD_D6_PIN               DIO_PIN6

#define LCD_D7_PORT              DIO_GROUPA
#define LCD_D7_PIN               DIO_PIN7




#define LCD_LINE_ONE           1
#define LCD_LINE_TWO           2
#endif /* LCD_CONFIG_H_ */
