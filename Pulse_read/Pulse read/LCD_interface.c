/*
 * LCD_interface.c
 *
 * Created: 8/29/2023 4:38:33 PM
 *  Author: youssef
 */

 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include <stdio.h>

#define F_CPU 16000000UL
#include <util/delay.h>


static void SHData(u8 copy_u8_data){
	
	u8 Loc_u8_in=0;
	u8 Loc_u8_pin[4]={ LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN };
		for(Loc_u8_in=0;Loc_u8_in<4;Loc_u8_in++){
			
			DIO_Vid_Set_Pin_Val(LCD_DPORT,Loc_u8_pin[Loc_u8_in],GET_BIT(copy_u8_data,Loc_u8_in));
		}
				
}

static void Send_Enable(void){
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,LOW);
	
}

void LCD_Vid_Send_Command(u8 copy_u8_command){
	
	/* SET RS PIN IN LCD TO SEND COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,LOW);
	
	/* SET RW PIN IN LCD TO WRITE */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	
	#if LCD_MODE == FOUR_BIT_MODE
		/*SEND HSB command*/
		SHData(copy_u8_command>>4);
		Send_Enable();
		/*LSB*/
		SHData(copy_u8_command);
		Send_Enable();
	#elif LCD_MODE == EIGHT_BIT_MODE
	/* SEND COMMAND */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_command);
	
	/*SEND ENABLE PULSE*/
	Send_Enable();
	#endif
}

void LCD_Vid_Send_Data(u8 copy_u8_data){
	
	/* SET RS PIN IN LCD TO SEND DATA */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,HIGH);
	
	/* SET RW PIN IN LCD TO WRITE */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW);
	
	#if LCD_MODE == FOUR_BIT_MODE
	/*SEND HSB command*/
	SHData(copy_u8_data>>4);
	Send_Enable();
	/*LSB*/
	SHData(copy_u8_data);
	Send_Enable();
	#elif LCD_MODE == EIGHT_BIT_MODE
	/* SEND COMMAND */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_data);
	
	/*SEND ENABLE PULSE*/
	Send_Enable();
	#endif	
	
}



void LCD_Vid_Init(){

	_delay_ms(40);
	
	/* SEND FUNCTION SET */
	
	#if LCD_MODE == FOUR_BIT_MODE
		SHData(0b0010);
		Send_Enable();
		SHData(0b0010);
		Send_Enable();
		SHData(0b1000);
		Send_Enable();
		#elif LCD_MODE EIGHT_BIT_MODE
			LCD_Vid_Send_Command(0x3C);
	#endif
	
	/* SEND ON/OFF Command*/
	
	LCD_Vid_Send_Command(0x0C);
		
	/* SEND CLEAR Command*/
	
	LCD_Vid_Send_Command(0X01);
	

}

void LCD_Vid_SEND_STRING(ch8*Add_u8_String)
{u8 line=0;
	while(*Add_u8_String!='\0')
	{
		LCD_Vid_Send_Data(*Add_u8_String);
		line++;
		Add_u8_String++;
		if(line==16){
			LCD_Vid_Send_Command(0xC0);
		}
	}
}


char *my_itoa(int num, char *str)
{
	if (str == NULL)
	{
		return NULL;
	}
	sprintf(str, "%d", num);
	return str;
}

void LCD_Vid_Send_NUM(u32 copy_u32_Num)
{
	char str[20];
	if (my_itoa(copy_u32_Num, str) != NULL)
	{
		LCD_Vid_SEND_STRING(str);
	}
}

/*
// void LCD_Vid_Send_NUM(u32 copy_u32_Num){
// 	ch8 ch[5];
// 	sprintf(copy_u32_Num ,ch,10);
// 	LCD_Vid_SEND_STRING(ch);
// 	
// 	
// }
*/


void LCD_Vid_GOTOxy(u8  copy_u8_x, u8 copy_u8_y){
	u8 Loc_u8_DDRAMaddress=0;
	if(copy_u8_y==0){
		
		Loc_u8_DDRAMaddress=copy_u8_x;
		
	}
	else if(copy_u8_y==1){
		
		Loc_u8_DDRAMaddress=copy_u8_x+0x40;
		
	}
	/* SET DDRAM */
	SET_BIT(Loc_u8_DDRAMaddress,7);
	LCD_Vid_Send_Command(Loc_u8_DDRAMaddress);
	
	
	
}

void LCD_Vid_CUSTOM_CHAR(ch8 copy_u8_data[8],u8 copy_u8_pattern,u8 copy_u8_x,u8 copy_u8_y){
	u8 Loc_u8_in;
	u8 Loc_u8_CGRAMadd=copy_u8_pattern*8;
	/* SET CGRAM */
	
	SET_BIT(Loc_u8_CGRAMadd,6);
	CLR_BIT(Loc_u8_CGRAMadd,7);
	/* WRITE DATA IN CGRAM */
	LCD_Vid_Send_Command(Loc_u8_CGRAMadd);
	for(Loc_u8_in=0;Loc_u8_in<8;Loc_u8_in++){
		LCD_Vid_Send_Data(copy_u8_data[Loc_u8_in]);
			
	}
	/* back to DDRAM to display data */
	LCD_Vid_GOTOxy(copy_u8_x,copy_u8_y);
	LCD_Vid_Send_Data(copy_u8_pattern);
	
}



	