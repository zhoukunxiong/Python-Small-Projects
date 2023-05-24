#include "LCD.h"
#include "Menu.h"
#include "getKeyNum.h"
#include "MatrixKeyboard.h"
#include "GlobalVariable.h"

/**********************************************************************
��������set_system_time
���ܣ�����ϵͳʱ��
������t1��ʱ��λ��t2��ʱ��λ��t3���ָ�λ��t4���ֵ�λ��t5�����λ��t6�����λ
����ֵ����
**********************************************************************/
void set_system_time(unsigned char t1, unsigned char t2, unsigned char t3, unsigned char t4, unsigned char t5, unsigned char t6)
{
	system_H = t1 * 10 + t2;
	system_M = t3 * 10 + t4;
	system_S = t5 * 10 + t6;
	show_time(system_H, system_M, system_S);
}

/**********************************************************************
��������set_alarm_clock_time
���ܣ���������ʱ��
������t1��ʱ��λ��t2��ʱ��λ��t3���ָ�λ��t4���ֵ�λ��t5�����λ��t6�����λ
����ֵ����
**********************************************************************/
void set_alarm_clock_time(unsigned char t1, unsigned char t2, unsigned char t3, unsigned char t4, unsigned char t5, unsigned char t6)
{
	alarm_H = t1 * 10 + t2;
	alarm_M = t3 * 10 + t4;
	alarm_S = t5 * 10 + t6;
	show_time(alarm_H, alarm_M, alarm_S);
}

/**********************************************************************
��������set_up
���ܣ���������ģʽ
��������
����ֵ����
**********************************************************************/
void set_up(void)
{
	// ��¼���λ��
	unsigned char move = 1;

	// ���¾������1����������ģʽ
	if (getMatrixKeyboardNum() == 1)
	{
		// ��ʼ�����λ��
		LCD_WriteCommand(0XC0);
		// ��ʾ��겢��˸
		LCD_WriteCommand(0X0F);

		while (1)
		{
			Key_Number = getKeyNum();
			// ֵ����
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
						// ���ù��λ��
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L++;
						if (H_L == 4)
							H_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H++;
						if (M_H == 6)
							M_H = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L++;
						if (M_L == 10)
							M_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H++;
						if (S_H == 6)
							S_H = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L++;
						if (S_L == 10)
							S_L = 0;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
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
						// ���ù��λ��
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L++;
						if (H_L == 5)
							H_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H++;
						if (M_H == 7)
							M_H = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L++;
						if (M_L == 10)
							M_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H++;
						if (S_H == 7)
							S_H = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L++;
						if (S_L == 10)
							S_L = 0;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC7);
					}
				}
			}
			// ֵ����
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
						// ���ù��λ��
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L--;
						if (H_L == -1)
							H_L = 3;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H--;
						if (M_H == -1)
							M_H = 5;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L--;
						if (M_L == -1)
							M_L = 9;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H--;
						if (S_H == -1)
							S_H = 5;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L--;
						if (S_L == -1)
							S_L = 9;
						set_system_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
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
						// ���ù��λ��
						LCD_WriteCommand(0XC0);
					}
					if (move == 2)
					{
						H_L--;
						if (H_L == -1)
							H_L = 3;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC1);
					}
					if (move == 4)
					{
						M_H--;
						if (M_H == -1)
							M_H = 5;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC3);
					}
					if (move == 5)
					{
						M_L--;
						if (M_L == -1)
							M_L = 9;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC4);
					}
					if (move == 7)
					{
						S_H--;
						if (S_H == -1)
							S_H = 5;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC6);
					}
					if (move == 8)
					{
						S_L--;
						if (S_L == -1)
							S_L = 9;
						set_alarm_clock_time(H_H, H_L, M_H, M_L, S_H, S_L);
						// ���ù��λ��
						LCD_WriteCommand(0XC7);
					}
				}
			}
			// ������ƶ�
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
			// �������
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
			// �˳�����ģʽ
			if (getMatrixKeyboardNum() == 2)
			{
				// LCD��λ
				LCD_Init();
				break;
			}
		}
	}
}
