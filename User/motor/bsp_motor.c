#include "bsp_motor.h"
#include "bsp_GeneralTim.h"


void Left_Motor(u16 speed) //speed取值0-1000
{
	
	speed = (throttle_max - throttle_min) * 30 / 100 + throttle_min;
	LC_CHG(speed);   //F为需频率 C为占空比 如F=2000，C取值0-1000
}

void Right_Motor(u16 speed) //speed取值0-1000
{
	
	speed = (throttle_max - throttle_min) * 30 / 100 + throttle_min;
	RC_CHG(speed);
}

//**********************************************************************************************
//							占空比调整
//**********************************************************************************************

/*左右轮脉冲占空比调整函数（用于TIM3）*/
void LC_CHG(u16 ChannelPulse)   //F为需频率 C为占空比 如F=2000，C取值0-1000
{
	//TIM_SetCompare3(TIM3,ChannelPulse);     
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
}
void RC_CHG(u16 ChannelPulse)   //F为需频率 C为占空比 如F=2000，C=0.5
{
	//TIM_SetCompare4(TIM3,ChannelPulse);     
	TIM_OCInitStructure.TIM_Pulse = ChannelPulse;
}
