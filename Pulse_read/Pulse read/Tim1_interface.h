/*
 * Tim1_interface.h
 *
 * Created: 10/5/2023 7:47:58 PM
 *  Author: user
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_


void Tim1_Vid_Fast_Pwm_ICR1_Init();

void Tim1_Vid_Set_Compare_Val(u32 copy_u32_val);

void Tim1_Vid_Init_Normal_Mode();
void Tim1_Vid_Reset_time();
u32 Tim1_u32_Read_Val();


#endif /* TIM1_INTERFACE_H_ */