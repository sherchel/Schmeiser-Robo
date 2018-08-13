/**
  ******************************************************************************
  * @file    main.c
  * @author 
  * @version 
  * @date   
  * @brief  
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "STA_INIT.h"


/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main ( void )
{
	/* ��ʼ�� */
	USARTx_Config ();                                                              //��ʼ������1
//	ESP8266_Init ();                                                               //��ʼ��WiFiģ��ʹ�õĽӿں�����
	LED_Init ();
	GENERAL_TIM_Init();
	Adc_Init();
	
	printf("ready\r\n");
  ESP8266_StaTcpClient_UnvarnishTest ();
	
	
  while ( 1 );
	
	
}


/*********************************************END OF FILE**********************/