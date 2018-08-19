#include "STA_test.h"
#include "bsp_esp8266.h"
#include "adc.h"
#include "delay.h"
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
	char cCmd [120];
	
	u16 adcL = 0, adcR = 0, adcF = 0;
	char strL[3]={0} , strR[3]={0} , strF[3]={0} ;
	

	//ESP8266_Cmd ( "AT+CWAUTOCONN=1", NULL, NULL, 15000 );
	
	//sprintf ( cCmd, "AT+SAVETRANSLINK=%d,\"%s\",%s,\"%s\"", macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port ,"TCP" );
	//ESP8266_Cmd ( cCmd, NULL, NULL, 15000 );

//	macESP8266_CH_ENABLE();		
	
//	ESP8266_AT_Test ();			//ESP work inspection
	
//	ESP8266_Net_Mode_Choose ( STA );		//serve as STP

//    //JoinAP's Ip  ***SET Here***
//	while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );	
//	
//	// One-to-many DISABLE
//	ESP8266_Enable_MultipleId ( DISABLE );
//	
//	
//	while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );
//	
//	while ( ! ESP8266_UnvarnishSend () );
	
	//STP's Configuration Finished
	
	
	while ( 1 )
	{		
		adcL = Get_Adc_Average(ADC_Channel_0, 1,10);
		adcR = Get_Adc_Average(ADC_Channel_1, 2,10);
		adcF = Get_Adc_Average(ADC_Channel_2, 3,10);

		strL[2]=adcL%10+0x30;  strL[1]=adcL/10%10+0x30;  strL[0]=adcL/100+0x30;
		strR[2]=adcR%10+0x30;  strR[1]=adcR/10%10+0x30;  strR[0]=adcR/100+0x30;
		strF[2]=adcF%10+0x30;  strF[1]=adcF/10%10+0x30;  strF[0]=adcF/100+0x30;

		sprintf(cStr, "LEFT_MOVE_%s\r\nRIGHT_MOVE_%s\r\nFIGHT_%s\r\n", strL, strR, strF);
		ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );               //发送数据,这里的Single_ID_0大概表示单人发送
		
		delay_us ( 100 );
		
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


