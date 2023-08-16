/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : HAL			                ***********/
/***********	Component : KEYPAD		                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 15/8/2023		            ***********/
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "util/delay.h"
#include "KEYPAD.h"

void KEYPAD_voidInit(void){
	/*set rows as input and columns as output*/
	DIO_SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_R0_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_R1_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_R2_PIN,DIO_INPUT);
	DIO_SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_R3_PIN,DIO_INPUT);

	DIO_SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_C0_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_C1_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_C2_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_C3_PIN,DIO_OUTPUT);

	/*enable pull up resistor*/
	DIO_SetPinValue(KEYPAD_ROWS_PORT,KEYPAD_R0_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_ROWS_PORT,KEYPAD_R1_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_ROWS_PORT,KEYPAD_R2_PIN,DIO_HIGH);
	DIO_SetPinValue(KEYPAD_ROWS_PORT,KEYPAD_R3_PIN,DIO_HIGH);

	/*initialize all keypad columns as deactivated*/
	DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_C0_PIN,KEYPAD_DEACTIVATE_COLUMN);
	DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_C1_PIN,KEYPAD_DEACTIVATE_COLUMN);
	DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_C2_PIN,KEYPAD_DEACTIVATE_COLUMN);
	DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_C3_PIN,KEYPAD_DEACTIVATE_COLUMN);

}
u8   KEYPAD_u8GetPressedKey(void){
	u8 u8RowIterator = 0;
	u8 u8ColumnIterator = 0;

	u8 KEPAD_u8ColPinArr[] = {KEYPAD_C0_PIN, KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};
	u8 KEPAD_u8RowPinArr[] = {KEYPAD_R0_PIN, KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN};

	for(;u8ColumnIterator < COLUMNS_NUMBER; u8ColumnIterator++){
		DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEPAD_u8ColPinArr[u8ColumnIterator] , KEYPAD_ACTIVATE_COLUMN);

		for(;u8RowIterator < ROWS_NUMBER; u8RowIterator++){
			if(DIO_GetPinValue(KEYPAD_ROWS_PORT, KEPAD_u8RowPinArr[u8RowIterator]) == KEYPAD_PRESSED_KEY){
				_delay_ms(50);
				while(DIO_GetPinValue(KEYPAD_ROWS_PORT, KEPAD_u8RowPinArr[u8RowIterator]) == KEYPAD_PRESSED_KEY);
				u8 returnArr [ROWS_NUMBER][COLUMNS_NUMBER]= KEYPAD_VALUES;
				return returnArr[u8RowIterator][u8ColumnIterator];
			}
		}
		DIO_SetPinValue(KEYPAD_COLUMNS_PORT,KEPAD_u8ColPinArr[u8ColumnIterator] , KEYPAD_DEACTIVATE_COLUMN);
	}
	return KEYPAD_NOT_PRESSED_KEY;
}

