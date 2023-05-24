#include <REGX52.H>
#include "GlobalVariable.h"

//�Ĵ�������
sfr IPH=0XB7;
/**********************************************************************
��������Timer1_Init
���ܣ�Timer1��ʼ��
��������
����ֵ����
**********************************************************************/
void Timer1_Init(void)
{
	//TMOD�Ĵ�������
	TMOD=TMOD&0X0F;
	TMOD=TMOD|0X20;
	//��ʱ�����ƼĴ���TCON����
	TF1=0;
	TR1=1;
	//��ʱ����ʼֵ���ã����2^16
	TL1=0xA4;//��ʱ100΢��
	TH1=0xA4;
	//�ж�������ƼĴ�������
	ET1=1;
	EA=1;
	//�ж����ȼ�����
	IPH=IPH|0X08;
	PT1=1;
}
/**********************************************************************
��������Timer1_Rountine
���ܣ�Timer1��ʱ���ж϶�ʱ1��
��������
����ֵ����
**********************************************************************/
unsigned char i=0;
unsigned char j=0;
void Timer1_Rountine(void) interrupt 3
{
	i++;
	//1����
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