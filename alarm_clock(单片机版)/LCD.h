#ifndef	__LCD__H_
#define	__LCD__H_

void LCD_Init(void);
void LCD_WriteCommand(unsigned char command);
void LCD_WriteData(unsigned char datas);
void LCD_ShowChar(unsigned char row,unsigned char columns,unsigned char character);
void LCD_ShowString(unsigned char row,unsigned char columns,unsigned char* string);
void LCD_ShowNumber(unsigned char row,unsigned char columns,unsigned int number,unsigned char length);
	
#endif