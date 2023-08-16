/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : DIO			                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 13/8/2023		            ***********/
/******************************************************************/

/*prototypes of functions*/
/*IO pins*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include <util/delay.h>

void DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		if(u8PinValCopy == DIO_HIGH){
			switch(u8PortIdCopy){
			case DIO_PORTA:
				SET_BIT(PORTA, u8PinIdCopy);
				break;
			case DIO_PORTB:
				SET_BIT(PORTB, u8PinIdCopy);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC, u8PinIdCopy);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD, u8PinIdCopy);
				break;
			}
		}else if(u8PinValCopy == DIO_LOW){
			switch(u8PortIdCopy){
			case DIO_PORTA:
				CLR_BIT(PORTA, u8PinIdCopy);
				break;
			case DIO_PORTB:
				CLR_BIT(PORTB, u8PinIdCopy);
				break;
			case DIO_PORTC:
				CLR_BIT(PORTC, u8PinIdCopy);
				break;
			case DIO_PORTD:
				CLR_BIT(PORTD, u8PinIdCopy);
				break;
			}

		}else{
			//not high nor low
		}
	}else{
		//out of range
	}
}

void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		if(u8PinDirCopy == DIO_OUTPUT){
			switch(u8PortIdCopy){
			case DIO_PORTA:
				SET_BIT(DDRA, u8PinIdCopy);
				break;
			case DIO_PORTB:
				SET_BIT(DDRB, u8PinIdCopy);
				break;
			case DIO_PORTC:
				SET_BIT(DDRC, u8PinIdCopy);
				break;
			case DIO_PORTD:
				SET_BIT(DDRD, u8PinIdCopy);
				break;
			}
		}else if(u8PinDirCopy == DIO_INPUT){
			switch(u8PortIdCopy){
			case DIO_PORTA:
				CLR_BIT(DDRA, u8PinIdCopy);
				break;
			case DIO_PORTB:
				CLR_BIT(DDRB, u8PinIdCopy);
				break;
			case DIO_PORTC:
				CLR_BIT(DDRC, u8PinIdCopy);
				break;
			case DIO_PORTD:
				CLR_BIT(DDRD, u8PinIdCopy);
				break;
			}

		}else{
			//not high nor low
		}
	}else{
		//out of range
	}
}
u8   DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy){
	if((u8PortIdCopy <= DIO_PORTD) && (u8PinIdCopy <= DIO_PIN7)){
		switch(u8PortIdCopy){
		case DIO_PORTA:
			return GET_BIT(PINA, u8PinIdCopy);
		case DIO_PORTB:
			return GET_BIT(PINB, u8PinIdCopy);
		case DIO_PORTC:
			return GET_BIT(PINC, u8PinIdCopy);
		case DIO_PORTD:
			return GET_BIT(PIND, u8PinIdCopy);
		}
	}else{

	}
	return 0xff;
}

/*IO ports*/
void DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValCopy){
	if(u8PortIdCopy <= DIO_PORTD){
		switch(u8PortIdCopy){
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
		}
	}else{
		//out of range
	}

}
void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy){
	if(u8PortIdCopy <= DIO_PORTD){
			switch(u8PortIdCopy){
			case DIO_PORTA:
				DDRA = u8PortDirCopy;
				break;
			case DIO_PORTB:
				DDRB = u8PortDirCopy;
				break;
			case DIO_PORTC:
				DDRC = u8PortDirCopy;
				break;
			case DIO_PORTD:
				DDRD = u8PortDirCopy;
				break;
			}
		}else{
			//out of range
		}
}


