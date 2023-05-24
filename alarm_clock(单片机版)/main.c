
#include "LCD.h"
#include "Time.h"
#include "Menu.h"
#include "SetUp.h"
#include "PageTurn.h"
#include "AlarmClock.h"

void main(void)
{
	// LCD��ʼ��
	LCD_Init();
	// ��ʱ����ʼ��
	Timer1_Init();

	while (1)
	{
		// ����չʾ
		Show_Menu();
		// ��ҳ
		page_turn();
		// ����ģʽ
		set_up();
		// ����
		alarm_clock();
	}
}
