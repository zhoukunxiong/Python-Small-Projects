
#include "LCD.h"
#include "Time.h"
#include "Menu.h"
#include "SetUp.h"
#include "PageTurn.h"
#include "AlarmClock.h"

void main(void)
{
	// LCD初始化
	LCD_Init();
	// 定时器初始化
	Timer1_Init();

	while (1)
	{
		// 界面展示
		Show_Menu();
		// 翻页
		page_turn();
		// 设置模式
		set_up();
		// 闹钟
		alarm_clock();
	}
}
