#include "bsp_motor.h"
#include "bsp_GeneralTim.h"
#include "stm32f10x_tim.h"



void Left_Motor(u16 speed) //speedȡֵ0-365
{
	
	speed = speed* 10000 / 500 +1 ;
	LC_CHG(speed);   
}

void Right_Motor(u16 speed) //speedȡֵ0-365
{
	
	speed = speed* 10000 / 500 +1 ;
	RC_CHG(speed);
}

void Fight_Motor(u16 speed) //speedȡֵ0-365
{
	
	speed = speed* 10000 / 500 +1 ;
	FC_CHG(speed);
}

//**********************************************************************************************
//							ռ�ձȵ���
//**********************************************************************************************

/*����������ռ�ձȵ�������������TIM3��*/
void LC_CHG(u16 ChannelPulse)   
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	TIM_Cmd(GENERAL_TIM, ENABLE);
}
void RC_CHG(u16 ChannelPulse) 
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	TIM_Cmd(GENERAL_TIM, ENABLE);
}

void FC_CHG(u16 ChannelPulse) 
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
	TIM_Cmd(GENERAL_TIM, ENABLE);
}
