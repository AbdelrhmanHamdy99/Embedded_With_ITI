/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : HAL			                ***********/
/***********	Component : KEYPAD		                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 15/8/2023		            ***********/
/******************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_ROWS_PORT         DIO_PORTB
#define KEYPAD_COLUMNS_PORT      DIO_PORTB

#define KEYPAD_R0_PIN            DIO_PIN0
#define KEYPAD_R1_PIN            DIO_PIN1
#define KEYPAD_R2_PIN            DIO_PIN2
#define KEYPAD_R3_PIN            DIO_PIN3

#define KEYPAD_C0_PIN            DIO_PIN4
#define KEYPAD_C1_PIN            DIO_PIN5
#define KEYPAD_C2_PIN            DIO_PIN6
#define KEYPAD_C3_PIN            DIO_PIN7

#define KEYPAD_PRESSED_KEY	     DIO_LOW
#define KEYPAD_NOT_PRESSED_KEY	 0xff

#define ROWS_NUMBER              4
#define COLUMNS_NUMBER           4

#define KEYPAD_ACTIVATE_COLUMN   DIO_LOW
#define KEYPAD_DEACTIVATE_COLUMN DIO_HIGH


#define KEYPAD_VALUES {{'7','8','9','/'},\
					   {'4','5','6','*'},\
					   {'1','2','3','-'},\
					   {'c','0','=','+'}}

void KEYPAD_voidInit(void);
u8   KEYPAD_u8GetPressedKey(void);
#endif /* KEYPAD_H_ */
