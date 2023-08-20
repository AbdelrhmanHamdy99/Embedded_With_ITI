/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : External Interrupt	        ***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : Aug 20, 2023	            ***********/
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"
#include "GIE.h"

#include <avr/io.h>

void EXTI_Init(EXTI_SenseControl_t senseControl){
	//enable general interrupt
	GI_Enable();

	//enable interrupt for int0
	SET_BIT(GICR,GICR_INT0);

	//setup int0 to work at falling edge
	MCUCR &= ~0x03;  //keep most significant 6 bits
	MCUCR |= (senseControl);
}


void EXTI1_Init(EXTI_SenseControl_t senseControl){
	//enable general interrupt
	GI_Enable();

	//enable interrupt for int0
	SET_BIT(GICR,GICR_INT1);

	//setup int1 to work as required
	MCUCR &= ~(0x03 << 2);  //keep most significant 6 bits
	MCUCR |= (senseControl << 2);
}

void EXTI2_Init(u8 senseControl){
	//enable general interrupt
	GI_Enable();

	//enable interrupt for int0
	SET_BIT(GICR,GICR_INT2);

	//setup int2 to work as required
	if(senseControl == EXTI2_FALLING_EDGE){
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
	}

	else if(senseControl == EXTI2_RISING_EDGE){
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	}

}

