/*
 * EXT_interface.h
 *
 * Created: 10/09/2023 16:26:39
 *  Author: AMIT
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_





#define   LOW_LEVEL         0 
#define   ANY_LOGIC_CHANGE  1 
#define   FALLING_EDGE      2
#define   RISING_EDGE       3


void EXT_Vid_Interrupt_Init(u8 INT_SENSE_CONTROL) ; 

void EXT_Vid_Enable_Interrupt0(); 
void EXT_Vid_Enable_Interrupt1() ;
void EXT_Vid_Enable_Interrupt2() ;

void Set_fun(void(*ptr)(void));




#endif /* EXT_INTERFACE_H_ */