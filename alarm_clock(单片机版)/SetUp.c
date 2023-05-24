#include "LCD.h"
#include "Menu.h"
#include "getKeyNum.h"
#include "MatrixKeyboard.h"
#include "GlobalVariable.h"

/**********************************************************************
函数名：set_system_time
功能：设置系统时间
参数：t1：时高位，t2：时低位，t3：分高位，t4：分低位，t5：秒高位，t6：秒低位
返回值：无
**********************************************************************/
void set_system_time(unsigned char t1, unsigned char t2, unsigned char t3, unsigned char t4, unsigned char t5, unsigned char t6)
{
	system_H = t1 * 10 + t2;
	system_M = t3 * 10 + t4;
	system_S = t5 * 10 + t6;
	show_time(system_H, system_M, system_S);
}

/**********************************************************************
函数名：set_alarm_clock_time
功能：设置闹钟时间
参数：t1：时高位，t2：时低位，t3：分高位，t4：分低位，t5：秒高位，t6：秒低位
返回值：无
**********************************************************************/
void set_alarm_clock_time(unsigned char t1, unsigned char t2, unsigned char t3, unsigned char t4, unsigned char t5, unsigned char t6)
{
	alarm_H = t1 * 10 + t2;
	alarm_M = t3 * 10 + t4;
	alarm_S = t5 * 10 + t6;
	show_time(alarm_H, alarm_M, alarm_S);
}

/**********************************************************************
函数名：set_up
功能：进入设置模式
参数：无
返回值：无
**********************************************************************/
void set_up(void)
{
	// 记录光标位置
	unsigned char move = 1;

	// 按下矩阵键盘1键进入设置模式
	if (getMatrixKeyboardNum() == 1)
	{
		// 初始化光标位置
		LCD_WriteCommand(0XC0);
		// 显示光标并闪烁
		LCD_WriteCommand(0X0F);

		while (1)
		{
			Key_Number = getKeyNum();
			// 值增加
			if (Key_Number == 1)
			{
				if (menu == 1)
				{
					H_L = system_H % 10;
					H_H = system_H / 10;
					M_L = system_M % 10;
					M_H = system_M / 10;
					S_L = system_S % 10;
					S_H = system_S / 10;
					if (move == 1)
					{
						H_H++;
						if (H_H == 3)
							H_H = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L++;
						if (H_L == 4)
							H_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H++;
						if (M_H == 6)
							M_H = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L++;
						if (M_L == 10)
							M_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H++;
						if (S_H == 6)
							S_H = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L++;
						if (S_L == 10)
							S_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC7);
					}
				}
				else if (menu == 2)
				{
					H_L = alarm_H % 10;
					H_H = alarm_H / 10;
					M_L = alarm_M % 10;
					M_H = alarm_M / 10;
					S_L = alarm_S % 10;
					S_H = alarm_S / 10;

					if (move == 1)
					{
						H_H++;
						if (H_H == 3)
							H_H = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L++;
						if (H_L == 5)
							H_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H++;
						if (M_H == 7)
							M_H = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L++;
						if (M_L == 10)
							M_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H++;
						if (S_H == 7)
							S_H = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L++;
						if (S_L == 10)
							S_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC7);
					}
				}
			}
			// 值减少
			if (Key_Number == 2)
			{
				if (menu == 1)
				{
					H_L = system_H % 10;
					H_H = system_H / 10;
					M_L = system_M % 10;
					M_H = system_M / 10;
					S_L = system_S % 10;
					S_H = system_S / 10;
					if (move == 1)
					{
						H_H--;
						if (H_H == -1)
							H_H = 2;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L--;
						if (H_L == -1)
							H_L = 3;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H--;
						if (M_H == -1)
							M_H = 5;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L--;
						if (M_L == -1)
							M_L = 9;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H--;
						if (S_H == -1)
							S_H = 5;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L--;
						if (S_L == -1)
							S_L = 9;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC7);
					}
				}
				else if (menu == 2)
				{
					H_L = alarm_H % 10;
					H_H = alarm_H / 10;
					M_L = alarm_M % 10;
					M_H = alarm_M / 10;
					S_L = alarm_S % 10;
					S_H = alarm_S / 10;
					if (move == 1)
					{
						H_H--;
						if (H_H == -1)
							H_H = 2;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L--;
						if (H_L == -1)
							H_L = 3;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H--;
						if (M_H == -1)
							M_H = 5;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L--;
						if (M_L == -1)
							M_L = 9;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H--;
						if (S_H == -1)
							S_H = 5;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L--;
						if (S_L == -1)
							S_L = 9;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// 设置光标位置
						LCD_WriteCommand(0XC7);
					}
				}
			}
			// 光标左移动
			if ((Key_Number == 3) && (move > 1))
			{
				LCD_WriteCommand(0X10);
				--move;
				if (move == 3 || move == 6)
				{
					--move;
					LCD_WriteCommand(0X10);
				}
			}
			// 光标右移
			else if ((Key_Number == 4) && (move < 8))
			{
				LCD_WriteCommand(0X14);
				++move;
				if (move == 3 || move == 6)
				{
					++move;
					LCD_WriteCommand(0X14);
				}
			}
			// 退出设置模式
			if (getMatrixKeyboardNum() == 2)
			{
				// LCD复位
				LCD_Init();
				break;
			}
		}
	}
}
