#include "getKeyNum.h"
#include "GlobalVariable.h"

/**********************************************************************
��������page_turn
���ܣ��˵����淭ҳ
��������
����ֵ����
**********************************************************************/
void page_turn(void)
{
	// ��ȡ����ֵ
	Key_Number=getKeyNum();
	// ���ҷ�ҳ
	if(Key_Number==3){menu-=1;Key_Number=0;}else if(Key_Number==4){menu+=1;Key_Number=0;}
	// ʹҳ����ѭ��
	if(menu==0){menu=2;}else if(menu==3){menu=1;}
}