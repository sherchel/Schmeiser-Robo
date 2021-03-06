#ifndef  __AP_TEST_H
#define	 __AP_TEST_H



#include "stm32f10x.h"



/********************************** 用户需要设置的参数**********************************/
#define   macUser_ESP8266_BulitApSsid         "LIN"      //要建立的热点的名称
#define   macUser_ESP8266_BulitApEcn           OPEN               //要建立的热点的加密方式
#define   macUser_ESP8266_BulitApPwd           "LIN"         //要建立的热点的密钥

#define   macUser_ESP8266_TcpServer_IP         "192.168.4.1"      //服务器开启的IP地址
#define   macUser_ESP8266_TcpServer_Port       "8080"             //服务器开启的端口   

#define   macUser_ESP8266_TcpServer_OverTime   "1800"             //服务器超时时间（单位：秒）



/********************************** 测试函数声明 ***************************************/
void                     ESP8266_StaTcpClient_UnvarnishTest  ( void );



#endif

