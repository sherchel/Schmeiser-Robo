#include "AP_test.h"
#include "bsp_esp8266.h"
#include "bsp_SysTick.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include "bsp_led.h"
#include "bsp_motor.h"



/**
  * @brief  ESP8266 （Sta Tcp Client）透传; AP(Using in Car)
  * @param  无
  * @retval 无
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	uint8_t ucId, ucLen;
	uint8_t Speed_Left, Speed_Right, Speed_Fight;

	char cStr [ 100 ] = { 0 }, cCh1,cCh2;

  char * pstr, * pCh1;
	

	macESP8266_CH_ENABLE();     	//CH:PortG.13
	
	ESP8266_AT_Test ();						//ESP work inspection
	
	ESP8266_Net_Mode_Choose ( AP );     	//serve as AP

  //Set AP's Ip  ***SET Here***
	while ( ! ESP8266_CIPAP ( macUser_ESP8266_TcpServer_IP ) );

  //Create WiFi  ***SET Here***
	while ( ! ESP8266_BuildAP ( macUser_ESP8266_BulitApSsid, macUser_ESP8266_BulitApPwd, macUser_ESP8266_BulitApEcn ) );	
	
	// One-to-many DISABLE
	ESP8266_Enable_MultipleId ( DISABLE );  
	
	//Start Server   ***SET Here***
	while ( !	ESP8266_StartOrShutServer ( ENABLE, macUser_ESP8266_TcpServer_Port, macUser_ESP8266_TcpServer_OverTime ) );

	//AP's Configuration Finished
	ESP8266_Inquire_ApIp ( cStr, 20 );
	printf ( "\r\n本模块WIFI为%s，密码开放\r\nAP IP 为：%s，开启的端口为：%s\r\n",
           macUser_ESP8266_BulitApSsid, cStr, macUser_ESP8266_TcpServer_Port );
	
	
	strEsp8266_Fram_Record .InfBit .FramLength = 0;
	strEsp8266_Fram_Record .InfBit .FramFinishFlag = 0;	
	
	while ( 1 )
	{		
		if ( strEsp8266_Fram_Record .InfBit .FramFinishFlag )
		{
			USART_ITConfig ( macESP8266_USARTx, USART_IT_RXNE, DISABLE ); //禁用串口接收中断
			strEsp8266_Fram_Record .Data_RX_BUF [ strEsp8266_Fram_Record .InfBit .FramLength ]  = '\0';

			//左轮速度指令
			if ( ( pstr = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "LEFT_MOVE_" ) ) != 0 ) 
			{
				cCh1 = * ( pstr + 10 );
				cCh2 = * ( pstr + 11 );
				
				Speed_Left = (cCh1 - 48) * 10 + (cCh2 - 48);
				Left_Motor( Speed_Left );
				
				
				//sprintf ( cStr, "CMD_LED_%d_ENDLED_END", ucLed1Status );
				
			}
			//右轮速度指令
			else if ( ( pstr = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "RIGHT_MOVE_" ) ) != 0 ) 
			{
				cCh1 = *(pstr + 11);
				cCh2 = *(pstr + 12);

				Speed_Right = (cCh1 - 48) * 10 + (cCh2 - 48);
				Right_Motor(Speed_Right);
				
				//sprintf ( cStr, "CMD_BUZZER_%d_ENDBUZZER_END", ucBuzzerStatus );
				
			}
			//武器系统速度指令 	
			else if ( ( ( pstr  = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "FIGHT_" ) ) != 0 )
			{
				cCh1 = *(pstr + 6);
				cCh2 = *(pstr + 7);

				Speed_Fight = (cCh1 - 48) * 10 + (cCh2 - 48);
				Fight_Motor(Speed_Fight);
			}

				
			
			
			strEsp8266_Fram_Record .InfBit .FramLength = 0;
			strEsp8266_Fram_Record .InfBit .FramFinishFlag = 0;	
			
			USART_ITConfig ( macESP8266_USARTx, USART_IT_RXNE, ENABLE ); //使能串口接收中断
			
		}
		
	}
	
		
}


