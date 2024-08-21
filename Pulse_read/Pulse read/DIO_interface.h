/*
 * DIO_interface.h
 *
 * Created: 8/27/2023 3:44:24 PM
 * Author: youssef
 * v0
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPE.h"
/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_Dir
* Purpose      : set pin dir (OUTPUT , INPUT)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value : void
*****************************************************************************/

void DIO_Vid_Set_Pin_Dir(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_dir);

/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_Val
* Purpose      : set pin val (OUTPUT , INPUT)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value : void
*****************************************************************************/

void DIO_Vid_Set_Pin_Val(u8 copy_u8_port, u8 copy_u8_pin, u8 copy_u8_val);

/*****************************************************************************
* Function Name: DIO_Get_Pin_Val
* Purpose      : get pin val
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value : u8
*****************************************************************************/

u8	 DIO_u8_Get_Pin_Val (u8 copy_u8_port, u8 copy_u8_pin);

/*****************************************************************************
* Function Name: DIO_Toggle_Pin_Val
* Purpose      : Toggle pin val
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value : Void
*****************************************************************************/
void DIO_Vid_Toggle_Pin_Val(u8 copy_u8_port, u8 copy_u8_pin);
/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Dir
* Purpose      : set port dir
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_dir
* Return value : Void
*****************************************************************************/

void DIO_Vid_Set_Port_Dir(u8 copy_u8_port,u8 copy_u8_dir);

/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Val
* Purpose      : set port val
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_dir
* Return value : Void
*****************************************************************************/
void DIO_Vid_Set_Port_Val(u8 copy_u8_port,u8 copy_u8_val);

/************************************************************************************************/

/* Status --> DIR */

#define OUTPUT 1
#define INPUT  0

/* PORT DIR */

#define PORT_OUTPUT 0xFF
#define PORT_INPUT  0x00

/* PORT DIR */

#define PORT_HIGH 0xFF
#define PORT_LOW  0x00

/* Status --> VAL */

#define HIGH 1
#define LOW  0

/* PORTS */

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* PINS */

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif /* DIO_INTERFACE_H_ */