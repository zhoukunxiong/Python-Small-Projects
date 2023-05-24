#include "GlobalVariable.h"
#include <REGX52.H>
#include "Menu.h"

/****************************************************************************************************
函数名：alarm_clock
功能：闹钟响1分钟
参数：无
返回值：无
****************************************************************************************************/
void alarm_clock(void)
{
	if((system_H==alarm_H)&&(system_M==alarm_M)&&(system_S==alarm_S))
	{
		while(1)
		{
			P1_5=~P1_5;
			if(system_M==(alarm_M+1))
				break;
			else show_time(system_H,system_M,system_S);
		}
	}
}