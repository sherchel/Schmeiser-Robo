#include "bsp_motor.h"
#include "bsp_GeneralTim.h"
#include "stm32f10x_tim.h"


#define throttle_max 200
#define throttle_min 50

void Left_Motor(u16 speed) //speed取值0-365
{
	
	speed = (throttle_max - throttle_min) * speed / 365 + throttle_min;
	LC_CHG(speed);   //F为需频率 C为占空比 如F=2000，C取值0-1000
}

void Right_Motor(u16 speed) //speed取值0-365
{
	
	speed = (throttle_max - throttle_min) * speed / 365 + throttle_min;
	RC_CHG(speed);
}

void Fight_Motor(u16 speed) //speed取值0-365
{
	
	speed = (throttle_max - throttle_min) * speed / 365 + throttle_min;
	FC_CHG(speed);
}

//**********************************************************************************************
//							占空比调整
//**********************************************************************************************

/*左右轮脉冲占空比调整函数（用于TIM3）*/
void LC_CHG(u16 ChannelPulse)   
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC1Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}
void RC_CHG(u16 ChannelPulse) 
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC2Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}

void FC_CHG(u16 ChannelPulse) 
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
	TIM_OC3Init(GENERAL_TIM, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM, TIM_OCPreload_Enable);
}
