/*
 * DIO_interface.c
 *
 * Created: 8/27/2023 3:45:12 PM
 *  Author: youssef
 * v0
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"




void DIO_Vid_Set_Pin_Dir(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_dir){
	
 if(copy_u8_dir==OUTPUT || copy_u8_dir==INPUT){
	 
	if(copy_u8_dir==OUTPUT){
		
		switch(copy_u8_port){
			
			case PORTA : SET_BIT(DDRA_REG,copy_u8_pin);break;
			case PORTB : SET_BIT(DDRB_REG,copy_u8_pin);break;
			case PORTC : SET_BIT(DDRC_REG,copy_u8_pin);break;
			case PORTD : SET_BIT(DDRD_REG,copy_u8_pin);break;
				
		}
	}
		
	else
	{
		
	
	switch(copy_u8_port){
		
		case PORTA :CLR_BIT(DDRA_REG,copy_u8_pin);break;
		case PORTB :CLR_BIT(DDRB_REG,copy_u8_pin);break;
		case PORTC :CLR_BIT(DDRC_REG,copy_u8_pin);break;
		case PORTD :CLR_BIT(DDRD_REG,copy_u8_pin);break;
		
	   }	
		
	}
}
		
		
		
		
		
	}
	
	
void DIO_Vid_Set_Pin_Val(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_val){
	
	
	 if(copy_u8_val==HIGH || copy_u8_val==LOW ){
		 
		 if(copy_u8_val==HIGH){
			 
			 switch(copy_u8_port){
				 
				 case PORTA : SET_BIT(PORTA_REG,copy_u8_pin);break;
				 case PORTB : SET_BIT(PORTB_REG,copy_u8_pin);break;
				 case PORTC : SET_BIT(PORTC_REG,copy_u8_pin);break;
				 case PORTD : SET_BIT(PORTD_REG,copy_u8_pin);break;
				 
			 }
		 }
		 
		 else
		 {
			 
			 
			 switch(copy_u8_port){
				 
				 case PORTA :CLR_BIT(PORTA_REG,copy_u8_pin);break;
				 case PORTB :CLR_BIT(PORTB_REG,copy_u8_pin);break;
				 case PORTC :CLR_BIT(PORTC_REG,copy_u8_pin);break;
				 case PORTD :CLR_BIT(PORTD_REG,copy_u8_pin);break;
				 
		   }	 
		}
	}
}

u8	 DIO_u8_Get_Pin_Val (u8 copy_u8_port, u8 copy_u8_pin)
{
	
	u8 LOC_u8_VAL=0 ;
	
	switch(copy_u8_port)
	{
		
		 case PORTA :LOC_u8_VAL=GET_BIT(PINA_REG,copy_u8_pin);break;
		 case PORTB :LOC_u8_VAL=GET_BIT(PINB_REG,copy_u8_pin);break;
		 case PORTC :LOC_u8_VAL=GET_BIT(PINC_REG,copy_u8_pin);break;
		 case PORTD :LOC_u8_VAL=GET_BIT(PIND_REG,copy_u8_pin);break;
		
		
	}
	
	return LOC_u8_VAL;
	
		
}
void DIO_Vid_Toggle_Pin_Val(u8 copy_u8_port, u8 copy_u8_pin){
	
	
	switch(copy_u8_port){
		
		
			 case PORTA : TOOGLE_BIT(PORTA_REG,copy_u8_pin);break;
			 case PORTB : TOOGLE_BIT(PORTB_REG,copy_u8_pin);break;
			 case PORTC : TOOGLE_BIT(PORTC_REG,copy_u8_pin);break;
			 case PORTD : TOOGLE_BIT(PORTD_REG,copy_u8_pin);break;
	}
	
}
void DIO_Vid_Set_Port_Dir(u8 copy_u8_port,u8 copy_u8_dir){
		
		
		
			 
		
		switch(copy_u8_port){
			
				case PORTA :DDRA_REG=PORT_OUTPUT;break;	
				case PORTB :DDRB_REG=PORT_OUTPUT;break;
				case PORTC :DDRC_REG=PORT_OUTPUT;break;
				case PORTD :DDRD_REG=PORT_OUTPUT;break;
							 
			
			
		}
		}

void DIO_Vid_Set_Port_Val(u8 copy_u8_port,u8 copy_u8_val){
	
			switch(copy_u8_port){
				
				case PORTA :PORTA_REG=copy_u8_val;break;
				case PORTB :PORTB_REG=copy_u8_val;break;
				case PORTC :PORTC_REG=copy_u8_val;break;
				case PORTD :PORTD_REG=copy_u8_val;break;
				
				
			}
}
		
		
	
	


	
	
	
	


