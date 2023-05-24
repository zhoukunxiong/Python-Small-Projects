#include "LCD.h"
#include "GlobalVariable.h"

/**********************************************************************
��������time_determine
���ܣ�	�ж�ʱ��λ������ʾ
������	columns����ʾ�У�time��ʱ��
����ֵ����
**********************************************************************/
void time_determine(unsigned char columns,unsigned char time)
{
	if(time>9){LCD_ShowNumber(2,columns,time,2);}
	else{LCD_ShowNumber(2,columns,0,1);LCD_ShowNumber(2,columns+1,time,1);}
}

/**********************************************************************
��������show_time
���ܣ�	LCD1602Һ����ʾʱ��
������	hour��ʱ��minute���֣�second����
����ֵ����
**********************************************************************/
void show_time(unsigned char hour,unsigned char minute,unsigned char second)
{
	// ��ʾʱ
	time_determine(1,hour);
	// ��ʾ�ָ���
	LCD_ShowChar(2,3,':');
	// ��ʾ��
	time_determine(4,minute);
	// ��ʾ�ָ���
	LCD_ShowChar(2,6,':');
	// ��ʾ��
	time_determine(7,second);
}

/**********************************************************************
�������� Show_Menu
���ܣ�	 ��ʾ�˵�
������	 ��
����ֵ�� ��
**********************************************************************/
void Show_Menu(void)
{
	// ����1
	if(menu==1)
	{
		// ������Ϣ
		LCD_ShowString(1,1,"system time:");
		// ��ʾʱ��
		show_time(system_H,system_M,system_S);
	}
	// ����2
	else if(menu==2)
	{
		// ������Ϣ
		LCD_ShowString(1,1,"alarm clock:");
		// ��ʾʱ��
		show_time(alarm_H,alarm_M,alarm_S);
	}	
}

