
// TIM��ͨ�ö�ʱ��-4·PWM���Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  
#include "bsp_usart1.h"

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{

	
	/* ��ʱ����ʼ�� */
	GENERAL_TIM_Init();
	
	ESP8266_Init ();//��ʼ��WiFiģ��ʹ�õĽӿں�����
	
	
	//printf("READY\r\n");
	
	ESP8266_StaTcpClient_UnvarnishTest ();
	
  while(1)
  {      
  }
}
/*********************************************END OF FILE**********************/
