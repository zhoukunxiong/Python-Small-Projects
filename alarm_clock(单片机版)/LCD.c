#include <REGX52.H>
#include "Delay500us.h"

// �궨��
#define LCD P0

// ���Ŷ���
sbit LCD_RS = P2 ^ 6;
sbit LCD_RW = P2 ^ 5;
sbit LCD_EP = P2 ^ 7;

/**********************************************************************
��������LCD_WriteCommand
���ܣ�LCD1602дָ��
������command��Ҫд���ָ��
����ֵ����
**********************************************************************/
void LCD_WriteCommand(unsigned char command)
{
	// ��������ģʽ
	LCD_RS = 0;

	// д��ָ��ģʽ
	LCD_RW = 0;
	LCD = command;

	// ����ָ��
	LCD_EP = 1;
	Delay500us();
	LCD_EP = 0;
	Delay500us();
}

/**********************************************************************
��������LCD_WriteData
���ܣ�LCD1602д����
������datas��Ҫд�������
����ֵ����
**********************************************************************/
void LCD_WriteData(unsigned char datas)
{
	// ��������ģʽ
	LCD_RS = 1;

	// д������ģʽ
	LCD_RW = 0;
	LCD = datas;

	// ��������
	LCD_EP = 1;
	Delay500us();
	LCD_EP = 0;
	Delay500us();
}

/********************************************************************************
��������LCD_Init
���ܣ�LCD1602Һ����ʼ��
��������
����ֵ����
********************************************************************************/
void LCD_Init(void)
{
	// ����
	LCD_WriteCommand(0X01);

	// ��λ
	LCD_WriteCommand(0X02);

	// ���뷽ʽ����,��д������ACֵ�Զ���1
	LCD_WriteCommand(0X06);

	// ������ʾ״̬:���濪�����ء���˸��
	LCD_WriteCommand(0X0C);

	// ������ƣ�ACֵ��1
	LCD_WriteCommand(0X14);

	// ���ù�����ʽ:8λ���ݣ�2����ʾ��5x10����
	LCD_WriteCommand(0X3C);
}

/**********************************************************************
��������LCD_ShowChar
���ܣ�LCD1602Һ����ʾһ���ַ�
������row����ʾ��λ�ã�columns����ʾ��λ�ã�character��Ҫ��ʾ���ַ�
����ֵ����
**********************************************************************/
void LCD_ShowChar(unsigned char row, unsigned char columns, unsigned char character)
{
	// ѡ���ַ���ʾλ��
	// LCD1602��һ��0X00~0X0F,�ڶ���0X40~0X4F
	if (row == 1)
	{
		LCD_WriteCommand(0X80 + (columns - 1));
	}
	else if (row == 2)
	{
		LCD_WriteCommand(0XC0 + (columns - 1));
	}
	// д��Ҫ��ʾ���ַ�
	LCD_WriteData(character);
}

/**********************************************************************
��������LCD_ShowString
���ܣ�LCD1602Һ����ʾ�ַ���
������row ��ʾ��λ�ã�columns ��ʾ��λ�ã�string Ҫ��ʾ���ַ�
����ֵ����
**********************************************************************/
void LCD_ShowString(unsigned char row, unsigned char columns, unsigned char *string)
{
	unsigned char i = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		LCD_ShowChar(row, columns + i, string[i]);
	}
}

/**********************************************************************
��������LCD_ShowNumber
���ܣ�LCD1602Һ����ʾһ������
������row ��ʾ��λ�ã�columns ��ʾ��λ�ã�number Ҫ��ʾ�����֣�length ���ֳ���
����ֵ����
**********************************************************************/
void LCD_ShowNumber(unsigned char row, unsigned char columns, unsigned int number, unsigned char length)
{
	unsigned char i;

	for (i = length; i > 0; i--)
	{
		LCD_ShowChar(row, columns + i - 1, '0' + number % 10);
		number /= 10;
	}
}