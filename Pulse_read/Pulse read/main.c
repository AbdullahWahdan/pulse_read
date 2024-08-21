/*
 * main.c
 *
 * Created: 10/8/2023 4:08:11 PM
 *  Author: user
 */ 

#include "DIO_interface.h"
#include "DIO_private.h"
#include "EXT_interface.h"
#include "EXT_private.h"
#include "GIE_interface.h"
#include "GIE_privte.h"
#include "intrupt_vector.h"
#include "STD_TYPE.h"
#include "MATH.h"
#include "Tim1_interface.h"
#include "Tim1_private.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

volatile static u32 on_ticks = 0;
volatile static u16 T_ovf_ticks = 0;
void SW_ICU();
int main(void)
{
	DIO_Vid_Set_Port_Dir(LCD_DPORT,0XF0);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	LCD_Vid_Init();
	DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
	
	GIE_Vid_Interrupt_Enable();
	EXT_Vid_Interrupt_Init(RISING_EDGE);
	EXT_Vid_Enable_Interrupt0();
	Tim1_Vid_Init_Normal_Mode();
	Set_fun(SW_ICU);
	 
    while(1)
    {
        Tim0_Vid_Fast_PWM(20);
		LCD_Vid_GOTOxy(0,0);
		
		LCD_Vid_Send_NUM(on_ticks);
		LCD_Vid_GOTOxy(0,1);
		
		LCD_Vid_Send_NUM(T_ovf_ticks);
    }
}

void SW_ICU()
{
	static u8 count = 0;
	count++;
	if (count == 1)
	{
		/*reset timer*/
		Tim1_Vid_Reset_time();
		EXT_Vid_Interrupt_Init(FALLING_EDGE);
		
	}
	
	else if (count==2)
	{
		on_ticks = Tim1_u32_Read_Val();
		EXT_Vid_Interrupt_Init(RISING_EDGE);
	}
	
	else if (count==3)
	{
		T_ovf_ticks = Tim1_u32_Read_Val();
		count = 0;
		Tim1_Vid_Reset_time();
	}
}