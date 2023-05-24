#include <REGX52.H>
#include "Delay500us.h"

// 宏定义
#define LCD P0

// 引脚定义
sbit LCD_RS = P2 ^ 6;
sbit LCD_RW = P2 ^ 5;
sbit LCD_EP = P2 ^ 7;

/**********************************************************************
函数名：LCD_WriteCommand
功能：LCD1602写指令
参数：command：要写入的指令
返回值：无
**********************************************************************/
void LCD_WriteCommand(unsigned char command)
{
	// 输入数据模式
	LCD_RS = 0;

	// 写入指令模式
	LCD_RW = 0;
	LCD = command;

	// 输入指令
	LCD_EP = 1;
	Delay500us();
	LCD_EP = 0;
	Delay500us();
}

/**********************************************************************
函数名：LCD_WriteData
功能：LCD1602写数据
参数：datas：要写入的数据
返回值：无
**********************************************************************/
void LCD_WriteData(unsigned char datas)
{
	// 输入数据模式
	LCD_RS = 1;

	// 写入数据模式
	LCD_RW = 0;
	LCD = datas;

	// 输入数据
	LCD_EP = 1;
	Delay500us();
	LCD_EP = 0;
	Delay500us();
}

/********************************************************************************
函数名：LCD_Init
功能：LCD1602液晶初始化
参数：无
返回值：无
********************************************************************************/
void LCD_Init(void)
{
	// 清屏
	LCD_WriteCommand(0X01);

	// 归位
	LCD_WriteCommand(0X02);

	// 输入方式设置,读写操作后，AC值自动加1
	LCD_WriteCommand(0X06);

	// 设置显示状态:画面开、光标关、闪烁关
	LCD_WriteCommand(0X0C);

	// 光标右移，AC值加1
	LCD_WriteCommand(0X14);

	// 设置工作方式:8位数据，2行显示，5x10点阵
	LCD_WriteCommand(0X3C);
}

/**********************************************************************
函数名：LCD_ShowChar
功能：LCD1602液晶显示一个字符
参数：row：显示行位置，columns：显示列位置，character：要显示的字符
返回值：无
**********************************************************************/
void LCD_ShowChar(unsigned char row, unsigned char columns, unsigned char character)
{
	// 选择字符显示位置
	// LCD1602第一行0X00~0X0F,第二行0X40~0X4F
	if (row == 1)
	{
		LCD_WriteCommand(0X80 + (columns - 1));
	}
	else if (row == 2)
	{
		LCD_WriteCommand(0XC0 + (columns - 1));
	}
	// 写入要显示的字符
	LCD_WriteData(character);
}

/**********************************************************************
函数名：LCD_ShowString
功能：LCD1602液晶显示字符串
参数：row 显示行位置，columns 显示列位置，string 要显示的字符
返回值：无
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
函数名：LCD_ShowNumber
功能：LCD1602液晶显示一个数字
参数：row 显示行位置，columns 显示列位置，number 要显示的数字，length 数字长度
返回值：无
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