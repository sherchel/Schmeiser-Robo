#ifndef __ADC_H
#define __ADC_H	
#include "stm32f10x.h"
#include "stm32f10x_adc.h"


void Adc_Init(void);
void ADC1_2_IRQHandler(void);
u16  Get_Adc(u8 ch,u8 order); 
u16 Get_Adc_Average(u8 ch,u8 order,u8 times); 
 
#endif 
