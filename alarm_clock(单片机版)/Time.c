#include <REGX52.H>
#include "GlobalVariable.h"

//寄存器定义
sfr IPH=0XB7;
/**********************************************************************
函数名：Timer1_Init
功能：Timer1初始化
参数：无
返回值：无
**********************************************************************/
void Timer1_Init(void)
{
	//TMOD寄存器配置
	TMOD=TMOD&0X0F;
	TMOD=TMOD|0X20;
	//定时器控制寄存器TCON配置
	TF1=0;
	TR1=1;
	//定时器初始值设置，最大2^16
	TL1=0xA4;//定时100微秒
	TH1=0xA4;
	//中断允许控制寄存器配置
	ET1=1;
	EA=1;
	//中断优先级配置
	IPH=IPH|0X08;
	PT1=1;
}
/**********************************************************************
函数名：Timer1_Rountine
功能：Timer1定时器中断定时1秒
参数：无
返回值：无
**********************************************************************/
unsigned char i=0;
unsigned char j=0;
void Timer1_Rountine(void) interrupt 3
{
	i++;
	//1秒钟
	if(i==100){++j;i=0;}
	if(j==100)
	{
		++system_S;
		if(system_S==60)
		{
			++system_M;
			system_S=0;
		}
		if(system_M==60)
		{
			++system_H;
			system_M=0;
			if(system_H==24)
				system_H=0;
		}
		j=0;
	}
}