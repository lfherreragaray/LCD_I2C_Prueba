/*
 * LCD.h
 *
 *  Created on: Nov 26, 2023
 *      Author: ubuntu
 */

#ifndef API_INC_LCD_H_
#define API_INC_LCD_H_
#include "I2C.h"
void LCD_Init(void);
void LCD_Write(uint8_t address,uint8_t data,bool_t rs);
void LCD_WriteChar(uint8_t address,char *data);
#endif /* API_INC_LCD_H_ */
