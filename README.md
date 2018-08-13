<<<<<<< HEAD
## 代码开发记录  
++CodeDesignRecord++       
@author sherchel

#### 2018.08.11
加入**ESP8266**作为服务器和客户端的代码

	ESP8266使能端PA5，重启端RST PA6
	AP_test.c/AP_main.c     服务器：用于小车
	STA_test.c/STA_main.c   客户端：用于遥控端


#### 2018.08.12
加入**无刷直流电机驱动**代码

	AP_test.c中识别到传输来的字符串如 "LEFT_MOVE_"
	调用bsp_motor.c中的Left_Motor()
	再通过LC_CHG(speed)改变占空比来调节电机转速
	更改电机油门引脚号应到定时器bsp_GeneralTim.h中更改
	目前为PA6/PA7/PB0/PB1

加入遥控器**ADC**代码

	STA_test.c中读取遥控器油门杆的ADC值
	目前读取的ADC值为PA0/PA1,分别为U,D,均为ADC1
	更改ADC通道应到ADC.c中更改
=======
# Schmeiser Robo

浠ｇ爜寮�鍙戣褰�  
CodeDesignRecord


2018.08.11
鍔犲叆ESP8266浣滀负鏈嶅姟鍣ㄥ拰瀹㈡埛绔殑浠ｇ爜
	ESP8266浣胯兘绔疨A5锛岄噸鍚RST PA6
	AP_test.c/AP_main.c     鏈嶅姟鍣細鐢ㄤ簬灏忚溅
	STA_test.c/STA_main.c   瀹㈡埛绔細鐢ㄤ簬閬ユ帶绔�


2018.08.12
鍔犲叆鏃犲埛鐩存祦鐢垫満椹卞姩浠ｇ爜
	AP_test.c涓瘑鍒埌浼犺緭鏉ョ殑瀛楃涓插 "LEFT_MOVE_" 锛岃皟鐢╞sp_motor.c涓殑Left_Motor()锛屽啀閫氳繃LC_CHG(speed)鏀瑰彉鍗犵┖姣旀潵璋冭妭鐢垫満杞��
	鏇存敼鐢垫満娌归棬寮曡剼鍙峰簲鍒板畾鏃跺櫒bsp_GeneralTim涓洿鏀�
	鐩墠涓篜A6/PA7/PB0/PB1

鍔犲叆閬ユ帶鍣ˋDC浠ｇ爜锛堜紶杈撻儴鍒嗘湭瀹屾垚锛�
	STA_test.c涓鍙栭仴鎺у櫒娌归棬鏉嗙殑ADC鍊�
	鐩墠璇诲彇鐨凙DC鍊间负PA0/PA1,鍒嗗埆涓篣,D,鍧囦负ADC1
	鏇存敼ADC閫氶亾搴斿埌ADC.c涓洿鏀�
>>>>>>> 418f57e2206e69200ba2e6c2c7a20625a794846a
