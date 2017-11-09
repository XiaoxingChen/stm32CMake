#include "stm32f10x.h"
#include "delay.h"
#include "common.h"
void GPIO_CONFIG(void);
int main(void)
{
	GPIO_CONFIG();
	delay_init();

	while(1)
	{
		GPIO_Write(GPIOA, 0xffff);
		GPIO_Write(GPIOB, 0xffff); 
		GPIO_Write(GPIOB, 0xffff);
		GPIO_SetBits(GPIOA, GPIO_Pin_10);
		delay_ms(500);
		GPIO_Write(GPIOA, 0);
		GPIO_Write(GPIOB, 0); 
		GPIO_Write(GPIOB, 0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_10);
		delay_ms(500);
	//while(1);
	}
	//return 0;
}
void GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
