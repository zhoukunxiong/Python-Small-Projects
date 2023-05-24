#include <REGX52.H>
#include "Delay.h"

sbit key1=P3^1;
sbit key2=P3^0;
sbit key3=P3^2;
sbit key4=P3^3;

/****************************************************************************************************
��������getKeyNum
���ܣ���ȡ���¶��������ļ���
��������
����ֵ�����°����ļ���
****************************************************************************************************/

unsigned char getKeyNum(void)
{
	unsigned char keyNum=0;
	
	if(key1==0)
	{
		Delay(10);//����
		while(key1==0);//�ȴ������ͷ�
		Delay(10);//����
		keyNum=1;
	}
	if(key2==0){Delay(10);while(key2==0);Delay(10);keyNum=2;}
	if(key3==0){Delay(10);while(key3==0);Delay(10);keyNum=3;}
	if(key4==0){Delay(10);while(key4==0);Delay(10);keyNum=4;}
	
	return keyNum;
}