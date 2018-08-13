# Schmeiser Robo

代码开发记录  
CodeDesignRecord


2018.08.11
加入ESP8266作为服务器和客户端的代码
	ESP8266使能端PA5，重启端RST PA6
	AP_test.c/AP_main.c     服务器：用于小车
	STA_test.c/STA_main.c   客户端：用于遥控端


2018.08.12
加入无刷直流电机驱动代码
	AP_test.c中识别到传输来的字符串如 "LEFT_MOVE_" ，调用bsp_motor.c中的Left_Motor()，再通过LC_CHG(speed)改变占空比来调节电机转速
	更改电机油门引脚号应到定时器bsp_GeneralTim中更改
	目前为PA6/PA7/PB0/PB1

加入遥控器ADC代码（传输部分未完成）
	STA_test.c中读取遥控器油门杆的ADC值
	目前读取的ADC值为PA0/PA1,分别为U,D,均为ADC1
	更改ADC通道应到ADC.c中更改
