#include "GlobalVariable.h"
#include <REGX52.H>
#include "Menu.h"

/****************************************************************************************************
��������alarm_clock
���ܣ�������1����
��������
����ֵ����
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