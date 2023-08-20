/******************************************************************/
/***********	Author    : Abdelrhman Hamdy Zakaria	***********/
/***********	Layer     : MCAL			            ***********/
/***********	Component : General Interrupt Enable	***********/
/***********	Version   : 1.00			            ***********/
/***********	Date      : Aug 20, 2023	            ***********/
/******************************************************************/

#ifndef GIE_H_
#define GIE_H_

#define SREG_I          7

void GI_Disable(void);
void GI_Enable(void);


#endif
