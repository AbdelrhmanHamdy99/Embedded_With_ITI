/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : External Interrupt	        ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : Aug 20, 2023	            ***********/
/******************************************************************/

#ifndef EXTI_H_
#define EXTI_H_

//interrupt 1 sense control
#define MCUCR_ISC11                    3
#define MCUCR_ISC10                    2

//interrupt 0 sense control
#define MCUCR_ISC01                    1
#define MCUCR_ISC00                    0

//interrupt 2 sense control
#define MCUCSR_ISC2                    6

//interrupt 0 sense control options
//interrupt 1 sense control options
typedef enum{
	LOW_LEVEL ,
	ANY_CHANGE ,
	FALLING_EDGE,
	RISING_EDGE
}EXTI_SenseControl_t;

//interrupt 2 sense control options
#define EXTI2_FALLING_EDGE             0
#define EXTI2_RISING_EDGE              1

// External Interrupt Request Enable
#define GICR_INT1                      7
#define GICR_INT0                      6
#define GICR_INT2                      5

// Interrupt Flag
#define GIFR_INTF1                     7
#define GIFR_INTF0                     6
#define GIFR_INTF2                     5

//external interrupts ports and pins
#define EXTI2_PORT                     PORTB
#define EXTI2_PIN                      2

#define EXTI1_PORT                     PORTD
#define EXTI1_PIN                      3

#define EXTI0_PORT                     PORTD
#define EXTI0_PIN                      2


void EXT0_Init(EXTI_SenseControl_t senseControl);
void EXT1_Init(EXTI_SenseControl_t senseControl);
void EXT2_Init(u8 senseControl);

#endif /* EXTI_H_ */
