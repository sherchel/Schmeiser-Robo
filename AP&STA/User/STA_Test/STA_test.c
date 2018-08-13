#include "STA_test.h"
#include "bsp_esp8266.h"
#include "bsp_SysTick.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>



volatile uint8_t ucTcpClosedFlag = 0;

char cStr [ 1500 ] = { 0 };



/**
  * @brief  ESP8266 ��Sta Tcp Client��͸��;STP(Using in Controller)
  * @param  ��
  * @retval ��
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	uint8_t ucStatus;
	
	char cStr [ 100 ] = { 0 };
	u16 adcL = 0, adcR = 0��adcF = 0;

	macESP8266_CH_ENABLE();		
	
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
		adcL = Get_Adc_Average(ADC_Channel_0, 10) / 1.4 * 99;
		adcD = Get_Adc_Average(ADC_Channel_1, 10) / 1.4 * 99;
		adcF = Get_Adc_Average(ADC_Channel_2, 10) / 1.4 * 99;
		
		sprintf(cStr, "LEFT_MOVE_%d\r\nRIGHT_MOVE_%d\r\nFIGHT_%d\r\n", adcL, adcD, adcF);

		ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );               //��������,�����Single_ID_0��ű�ʾ���˷���
		
		Delay_us ( 100000 );
		
		if ( ucTcpClosedFlag )                                             //����Ƿ�ʧȥ����
		{
			ESP8266_ExitUnvarnishSend ();                                    //�˳�͸��ģʽ
			
			do ucStatus = ESP8266_Get_LinkStatus ();                         //��ȡ����״̬
			while ( ! ucStatus );
			
			if ( ucStatus == 4 )                                             //ȷ��ʧȥ���Ӻ�����
			{
				//printf ( "\r\n���������ȵ�ͷ����� ......\r\n" );
				
				while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );
				
				while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );
				
				//printf ( "\r\n�����ȵ�ͷ������ɹ�\r\n" );

			}
			
			while ( ! ESP8266_UnvarnishSend () );		
			
		}
	}
	
		
}


