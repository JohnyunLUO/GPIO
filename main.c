#include "stm32f10x.h" 
#include "GPIO_STM32F10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

//#define USE_FULL_ASSERT 1;

void LED_GPIO_config(){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1; //Blue
	
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5; //RED
	
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
}

void delay(int us){

		while(us--){
			int count=9;
			while(count--);
		}
}

int us=0;	
int main(void)
{		
	LED_GPIO_config();
	while(1){
		GPIO_PinWrite (GPIOB,0, 0);
		GPIO_PinWrite (GPIOB,1, 1);
		GPIO_PinWrite (GPIOB,5, 1);
		delay(0xFFFF);
		GPIO_PinWrite (GPIOB,0, 1);
		GPIO_PinWrite (GPIOB,1, 0);
		GPIO_PinWrite (GPIOB,5, 1);
		delay(0xFFFF);
		GPIO_PinWrite (GPIOB,0, 1);
		GPIO_PinWrite (GPIOB,1, 1);
		GPIO_PinWrite (GPIOB,5, 0);
		delay(0xFFFF);
	
	}	
	
	return 0;	
}




void SystemInit(void)
{	
}






/*********************************************END OF FILE**********************/

