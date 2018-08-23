
// TIM—通用定时器-4路PWM输出应用
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  
#include "bsp_usart1.h"

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{

	
	/* 定时器初始化 */
	GENERAL_TIM_Init();
	
	ESP8266_Init ();//初始化WiFi模块使用的接口和外设
	
	
	//printf("READY\r\n");
	
	ESP8266_StaTcpClient_UnvarnishTest ();
	
  while(1)
  {      
  }
}
/*********************************************END OF FILE**********************/
