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
#include "AP_INIT.h"


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main ( void )
{
	/* 初始化 */
		USARTx_Config ();                                                              //初始化串口1
		ESP8266_Init ();                                                               //初始化WiFi模块使用的接口和外设
		LED_Init ();
		GENERAL_TIM_Init();

	  printf("READY\r\n");
		ESP8266_StaTcpClient_UnvarnishTest ();
	
	
  while ( 1 );
	
	
}


/*********************************************END OF FILE**********************/
