#include "LCD.h"
#include "GlobalVariable.h"

/**********************************************************************
函数名：time_determine
功能：	判断时间位数并显示
参数：	columns：显示列，time：时间
返回值：无
**********************************************************************/
void time_determine(unsigned char columns,unsigned char time)
{
	if(time>9){LCD_ShowNumber(2,columns,time,2);}
	else{LCD_ShowNumber(2,columns,0,1);LCD_ShowNumber(2,columns+1,time,1);}
}

/**********************************************************************
函数名：show_time
功能：	LCD1602液晶显示时间
参数：	hour：时，minute：分，second：秒
返回值：无
**********************************************************************/
void show_time(unsigned char hour,unsigned char minute,unsigned char second)
{
	// 显示时
	time_determine(1,hour);
	// 显示分隔符
	LCD_ShowChar(2,3,':');
	// 显示分
	time_determine(4,minute);
	// 显示分隔符
	LCD_ShowChar(2,6,':');
	// 显示秒
	time_determine(7,second);
}

/**********************************************************************
函数名： Show_Menu
功能：	 显示菜单
参数：	 无
返回值： 无
**********************************************************************/
void Show_Menu(void)
{
	// 界面1
	if(menu==1)
	{
		// 界面信息
		LCD_ShowString(1,1,"system time:");
		// 显示时间
		show_time(system_H,system_M,system_S);
	}
	// 界面2
	else if(menu==2)
	{
		// 界面信息
		LCD_ShowString(1,1,"alarm clock:");
		// 显示时间
		show_time(alarm_H,alarm_M,alarm_S);
	}	
}

