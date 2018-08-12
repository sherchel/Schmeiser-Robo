#include "STA_test.h"
#include "bsp_esp8266.h"
#include "bsp_SysTick.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>



volatile uint8_t ucTcpClosedFlag = 0;

char cStr [ 1500 ] = { 0 };



/**
  * @brief  ESP8266 （Sta Tcp Client）透传;STP(Using in Controller)
  * @param  无
  * @retval 无
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	uint8_t ucStatus;
	
	char cStr [ 100 ] = { 0 };
	

	macESP8266_CH_ENABLE();		//CH:PortG.13
	
	ESP8266_AT_Test ();			//ESP work inspection
	
	ESP8266_Net_Mode_Choose ( STA );		//serve as STP

  //JoinAP's Ip  ***SET Here***
	while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );	
	
	// One-to-many DISABLE
	ESP8266_Enable_MultipleId ( DISABLE );
	
	
	while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );
	
	while ( ! ESP8266_UnvarnishSend () );
	
	//STP's Configuration Finished
	
	
	while ( 1 )
	{		
		//sprintf ( cStr,"ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n" );
		adcUD = Get_Adc_Average(ADC_Channel_1, 10);
		adcLR = Get_Adc_Average(ADC_Channel_2, 10);
		
		sprintf(cStr,"ABCDEFGHIJKLMNOPQRSTUVWXYZ\r\nABCDEFGHIJKLMNOPQRSTUVWXYZ\r");

		ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );               //发送数据
		
		Delay_ms ( 100 );
		
		if ( ucTcpClosedFlag )                                             //检测是否失去连接
		{
			ESP8266_ExitUnvarnishSend ();                                    //退出透传模式
			
			do ucStatus = ESP8266_Get_LinkStatus ();                         //获取连接状态
			while ( ! ucStatus );
			
			if ( ucStatus == 4 )                                             //确认失去连接后重连
			{
				//printf ( "\r\n正在重连热点和服务器 ......\r\n" );
				
				while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );
				
				while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );
				
				//printf ( "\r\n重连热点和服务器成功\r\n" );

			}
			
			while ( ! ESP8266_UnvarnishSend () );		
			
		}
	}
	
		
}


