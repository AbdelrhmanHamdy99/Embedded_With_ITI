/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : HAL			                ***********/
/***********	Component : CLCD		                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 14/8/2023		            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "util/delay.h"

void CLCD_voidSendData(u8 u8DataCopy){
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT,u8DataCopy);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);

}
void CLCD_voidSendCommand(u8 u8CommandCopy){
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_LOW);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT,u8CommandCopy);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}
void CLCD_voidInit(void){
	/*initialize DIO*/
	DIO_SetPortDirection(CLCD_DATA_PORT,0xFF);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_OUTPUT);
	/*lcd init*/
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001111);
	CLCD_voidSendCommand(0b00000001);

}
