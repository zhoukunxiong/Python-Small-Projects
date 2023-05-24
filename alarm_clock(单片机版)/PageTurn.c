#include "getKeyNum.h"
#include "GlobalVariable.h"

/**********************************************************************
函数名：page_turn
功能：菜单界面翻页
参数：无
返回值：无
**********************************************************************/
void page_turn(void)
{
	// 获取按键值
	Key_Number=getKeyNum();
	// 左右翻页
	if(Key_Number==3){menu-=1;Key_Number=0;}else if(Key_Number==4){menu+=1;Key_Number=0;}
	// 使页面能循环
	if(menu==0){menu=2;}else if(menu==3){menu=1;}
}