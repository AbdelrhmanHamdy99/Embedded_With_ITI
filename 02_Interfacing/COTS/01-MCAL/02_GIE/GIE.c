/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : General Interrupt Enable	***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : Aug 20, 2023	            ***********/
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE.h"
#include <avr/io.h>

void GI_Disable(){
	CLR_BIT(SREG, SREG_I);
}

void GI_Enable(){
	SET_BIT(SREG, SREG_I);
}
