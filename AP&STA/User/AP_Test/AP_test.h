#ifndef  _AP__TEST_H
#define	 __AP_TEST_H



#include "stm32f10x.h"


/********************************** �û���Ҫ���õĲ���**********************************/
#define   macUser_ESP8266_BulitApSsid         "BinghuoLink"      //Ҫ�������ȵ������
#define   macUser_ESP8266_BulitApEcn           OPEN               //Ҫ�������ȵ�ļ��ܷ�ʽ
#define   macUser_ESP8266_BulitApPwd           "wildfire"         //Ҫ�������ȵ����Կ

#define   macUser_ESP8266_TcpServer_IP         "192.168.123.169"      //������������IP��ַ
#define   macUser_ESP8266_TcpServer_Port       "8080"             //�����������Ķ˿�   

#define   macUser_ESP8266_TcpServer_OverTime   "1800"             //��������ʱʱ�䣨��λ���룩



/********************************** ���Ժ������� ***************************************/
void                     ESP8266_StaTcpClient_UnvarnishTest  ( void );



#endif

