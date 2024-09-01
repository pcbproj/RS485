#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"

#include "main.h"

/*
Передача тестовой строки через переходник RS485 - USB от ПК в МК. 
МК принимает строку и отправляет на нее свой ответ. 

ПК передает строку 8 байт: 0x11 0x22 0x33 0x44 0x55 0x66 0x77 0x88
МК проверяет. Если разница между байтами = 0x11 и 8 байт длина, то строка верная. 
и отправляет в ответ ее же.
Если строка не верная ( длина или разница в значений байтов), то МК отправляет байт ошибки = 0xEE

*/


void SysTick_Handler(void){		// прервание от Systick таймера, выполняющееся с периодом 1 мкс

	timer_counter();

}


int main(void) {

	RCC_Init();
	
	GPIO_Init();

	USART2_Init();

	SysTick_Config(SYSTICK_TIMER_CONST);		// systick period 1 us

	LED1_OFF();
	LED2_OFF();
	LED3_OFF();


	while(1){
			
			Delay_ms(500);
			LED1_TOGGLE();
			Delay_ms(500);
			LED1_TOGGLE();

			Delay_ms(500);
			LED2_TOGGLE();
			Delay_ms(500);
			LED2_TOGGLE();

			Delay_ms(500);
			LED3_TOGGLE();
			Delay_ms(500);
			LED3_TOGGLE();
			

	}	// while(1)
}	// main()

/*************************** End of file ****************************/
