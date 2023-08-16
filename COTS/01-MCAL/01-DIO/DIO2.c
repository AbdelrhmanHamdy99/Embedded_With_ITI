/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : DIO			                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 16/8/2023		            ***********/
/******************************************************************/

#include "DIO2.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy, u8 u8PinDirectionCopy){
	//invalid port or invalid pin
	if(u8PortIdCopy > DIO_PORTD ||u8PinIdCopy > DIO_PIN7)
		return;

	switch(u8PortIdCopy){
	case DIO_PORTA:
		switch(u8PinDirectionCopy){
		case DIO_OUTPUT: SET_BIT(DDRA, u8PinIdCopy) ; break;
		case DIO_INPUT : CLR_BIT(DDRA, u8PinIdCopy) ; break;
		}
		break;
	case DIO_PORTB:
		switch(u8PinDirectionCopy){
		case DIO_OUTPUT: SET_BIT(DDRB, u8PinIdCopy) ; break;
		case DIO_INPUT : CLR_BIT(DDRB, u8PinIdCopy) ; break;
		}
		break;
	case DIO_PORTC:
		switch(u8PinDirectionCopy){
		case DIO_OUTPUT: SET_BIT(DDRC, u8PinIdCopy) ; break;
		case DIO_INPUT : CLR_BIT(DDRC, u8PinIdCopy) ; break;
		}
		break;
	case DIO_PORTD:
		switch(u8PinDirectionCopy){
		case DIO_OUTPUT: SET_BIT(DDRD, u8PinIdCopy) ; break;
		case DIO_INPUT : CLR_BIT(DDRD, u8PinIdCopy) ; break;
		}
		break;
	}
}

void DIO_SetPinValue    (u8 u8PortIdCopy,u8 u8PinIdCopy, u8 u8PinValCopy){
	//invalid port or invalid pin
		if(u8PortIdCopy > DIO_PORTD ||u8PinIdCopy > DIO_PIN7)
			return;

		switch(u8PortIdCopy){
		case DIO_PORTA:
			switch(u8PinValCopy){
			case DIO_OUTPUT: SET_BIT(PORTA, u8PinIdCopy) ; break;
			case DIO_INPUT : CLR_BIT(PORTA, u8PinIdCopy) ; break;
			}
			break;
		case DIO_PORTB:
			switch(u8PinValCopy){
			case DIO_OUTPUT: SET_BIT(PORTB, u8PinIdCopy) ; break;
			case DIO_INPUT : CLR_BIT(PORTB, u8PinIdCopy) ; break;
			}
			break;
		case DIO_PORTC:
			switch(u8PinValCopy){
			case DIO_OUTPUT: SET_BIT(PORTC, u8PinIdCopy) ; break;
			case DIO_INPUT : CLR_BIT(PORTC, u8PinIdCopy) ; break;
			}
			break;
		case DIO_PORTD:
			switch(u8PinValCopy){
			case DIO_OUTPUT: SET_BIT(PORTD, u8PinIdCopy) ; break;
			case DIO_INPUT : CLR_BIT(PORTD, u8PinIdCopy) ; break;
			}
			break;
		}
}
u8   DIO_GetPinValue    (u8 u8PortIdCopy,u8 u8PinIdCopy){
	if(u8PortIdCopy > DIO_PORTD ||u8PinIdCopy > DIO_PIN7)
		return -1;/*indicate invalid pin or port*/

	switch (u8PortIdCopy) {
		case DIO_PORTA:
			return GET_BIT(PINA,u8PinIdCopy);
		case DIO_PORTB:
			return GET_BIT(PINB,u8PinIdCopy);
		case DIO_PORTC:
			return GET_BIT(PINC,u8PinIdCopy);
		case DIO_PORTD:
			return GET_BIT(PIND,u8PinIdCopy);
		default:
			return -1;
	}
}

void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirectionCopy){
	switch (u8PortIdCopy) {
		case DIO_PORTA:
			DDRA = u8PortDirectionCopy;
			break;
		case DIO_PORTB:
			DDRB = u8PortDirectionCopy;
			break;
		case DIO_PORTC:
			DDRC = u8PortDirectionCopy;
			break;
		case DIO_PORTD:
			DDRD = u8PortDirectionCopy;
			break;
		default:
			break;
	}
}
void DIO_SetPortValue    (u8 u8PortIdCopy, u8 u8PortValCopy){
	switch (u8PortIdCopy) {
		case DIO_PORTA:
			PORTA = u8PortValCopy;
			break;
		case DIO_PORTB:
			PORTB = u8PortValCopy;
			break;
		case DIO_PORTC:
			PORTC = u8PortValCopy;
			break;
		case DIO_PORTD:
			PORTD = u8PortValCopy;
			break;
		default:
			break;
		}
}


