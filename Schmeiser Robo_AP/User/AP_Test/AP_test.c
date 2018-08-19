#include "AP_test.h"
#include "bsp_esp8266.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include "bsp_led.h"
#include "bsp_motor.h"
#include "delay.h"



/**
  * @brief  ESP8266 ��Sta Tcp Client��͸��; AP(Using in Car)
  * @param  ��
  * @retval ��
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	uint8_t ucId, ucLen;
	uint16_t Speed_Left, Speed_Right, Speed_Fight;

	char cStr [ 100 ] = { 0 }, cCh1,cCh2,cCh3;

  char * pstr;
	

//	macESP8266_CH_ENABLE();
	
//	ESP8266_AT_Test ();						//ESP work inspection

//	ESP8266_Net_Mode_Choose ( AP );     	//serve as AP

  //Set AP's Ip  ***SET Here***
//	while ( ! ESP8266_CIPAP ( macUser_ESP8266_TcpServer_IP ) );

//  //Create WiFi  ***SET Here***
//	while ( ! ESP8266_BuildAP ( macUser_ESP8266_BulitApSsid, macUser_ESP8266_BulitApPwd, macUser_ESP8266_BulitApEcn ) );	
	
	// One-to-many ENABLE
	ESP8266_Enable_MultipleId (ENABLE);
	
	//Start Server   ***SET Here***
	ESP8266_StartOrShutServer ( ENABLE, macUser_ESP8266_TcpServer_Port, macUser_ESP8266_TcpServer_OverTime );
	//while ( !	ESP8266_StartOrShutServer ( ENABLE, macUser_ESP8266_TcpServer_Port, macUser_ESP8266_TcpServer_OverTime ) );

	//AP's Configuration Finished
//	ESP8266_Inquire_ApIp ( cStr, 20 );
//	printf ( "\r\n��ģ��WIFIΪ%s�����뿪��\r\nAP IP Ϊ��%s�������Ķ˿�Ϊ��%s\r\n",
//           macUser_ESP8266_BulitApSsid, cStr, macUser_ESP8266_TcpServer_Port );
	
	
	strEsp8266_Fram_Record .InfBit .FramLength = 0;
	strEsp8266_Fram_Record .InfBit .FramFinishFlag = 1;	
	
	while ( 1 )
	{		
		
	//	printf("READY2\r\n");
		if ( strEsp8266_Fram_Record .InfBit .FramFinishFlag )
		{
			USART_ITConfig ( macESP8266_USARTx, USART_IT_RXNE, DISABLE ); //���ô��ڽ����ж�
			strEsp8266_Fram_Record .Data_RX_BUF [ strEsp8266_Fram_Record .InfBit .FramLength ]  = '\0';

			//�����ٶ�ָ��
			if ( ( pstr = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "LEFT_MOVE_" ) ) != 0 ) 
			{
				cCh1 = * ( pstr + 10 );
				cCh2 = * ( pstr + 11 );
				cCh3 = * ( pstr + 12 );
				
				Speed_Left = (cCh1 - 48) * 100 + (cCh2 - 48) * 10 + (cCh3 - 48);
				Left_Motor( Speed_Left );
				
				
			}
			//�����ٶ�ָ��
			if ( ( pstr = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "RIGHT_MOVE_" ) ) != 0 ) 
			{
				cCh1 = * ( pstr + 11 );
				cCh2 = * ( pstr + 12 );
				cCh3 = * ( pstr + 13 );

				Speed_Right = (cCh1 - 48) * 100 + (cCh2 - 48) * 10 + (cCh3 - 48);
				Right_Motor(Speed_Right);
				
				
			}
			//����ϵͳ�ٶ�ָ�� 	
			if ( ( pstr  = strstr ( strEsp8266_Fram_Record .Data_RX_BUF, "FIGHT_" ) ) != 0 )
			{
				cCh1 = * ( pstr + 6 );
				cCh2 = * ( pstr + 7 );
				cCh3 = * ( pstr + 8 );

				Speed_Fight = (cCh1 - 48) * 100 + (cCh2 - 48) * 10 + (cCh3 - 48);
			  Fight_Motor(Speed_Fight);
			}

				
			
			
			strEsp8266_Fram_Record .InfBit .FramLength = 0;
			strEsp8266_Fram_Record .InfBit .FramFinishFlag = 0;	
			
			USART_ITConfig ( macESP8266_USARTx, USART_IT_RXNE, ENABLE ); //ʹ�ܴ��ڽ����ж�
			
		}
		
	}
	
		
}


