/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : DIO			                ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : 13/8/2023		            ***********/
/******************************************************************/

#ifndef DIO_H_
#define DIO_H_

/*ports definition*/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

/*pins definitions*/
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

/*pin direction*/
#define DIO_INPUT  0
#define DIO_OUTPUT 1

/*pin value options*/
#define DIO_LOW    0
#define DIO_HIGH   1


/*prototypes of functions*/
/*IO pins*/
void DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy);
void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);
u8   DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

/*IO ports*/
void DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValCopy);
void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy);

#endif /* DIO_H_ */
