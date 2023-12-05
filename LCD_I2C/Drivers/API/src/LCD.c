/*
 * LCD.c
 *
 *  Created on: Nov 26, 2023
 *      Author: ubuntu
 */
#include "LCD.h"
#define E 0x4
#define RS 0x1
#define RW 0x2
void LCD_Init()
    {
    //I2C_device();
    I2C_Init();
	//Modo 4bits
	HAL_Delay(50);
	LCD_Write(0x27,0x30,0);
        HAL_Delay(5);
        LCD_Write(0x27,0x30,0);
        HAL_Delay(1);
        LCD_Write(0x27,0x30,0);
        HAL_Delay(10);
        LCD_Write(0x27,0x20,0);
        HAL_Delay(10);
        //Inicializacion
        LCD_Write(0x27,0x28,0);
        HAL_Delay(1);
        LCD_Write(0x27,0x08,0);
        HAL_Delay(1);
        LCD_Write(0x27,0x01,0);
        HAL_Delay(2);
        LCD_Write(0x27,0x06,0);
        HAL_Delay(1);
        LCD_Write(0x27,0x0C,0);
    }

void LCD_Write(uint8_t address,uint8_t data,bool_t rs)
    {
    uint8_t Data[4]={0};

    Data[0]=(data&0xf0)|0x4|rs|0x8;
    Data[1]=(data&0xf0)|rs|0x8;
    Data[2]=((data<<4)&0xf0)|0x4|rs|0x8;
    Data[3]=((data<<4)&0xf0)|rs|0x8;
    I2C_transmit(address,(uint8_t*)&Data);

    }
void LCD_WriteChar(uint8_t address,char *data){

    for(int i=0;i<strlen(data);i++)
	{
	LCD_Write(address,data[i],1);
	}

}
