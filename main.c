#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"

#include "main.h"

/*
Передача тестового байта через переходник RS485 - USB от ПК в МК. 
МК принимает байт и отправляет на него свой ответ - строку 
"RS485 RX OK"
*/


void SysTick_Handler(void){		// прервание от Systick таймера, выполняющееся с периодом 1 мкс

	timer_counter();

}


int main(void) {
	uint8_t rs485_rx_byte;
	uint8_t rs485_tx_array[12] = {"RS485 RX OK\n"};

	RCC_Init();
	
	GPIO_Init();

	USART6_Init();

	SysTick_Config(SYSTICK_TIMER_CONST);		// systick period 1 us

	LED1_OFF();
	LED2_OFF();
	LED3_OFF();


	while(1){
			
		
		if( !( usart6_receive_byte( &rs485_rx_byte) ) ){	// if received byte
			LED2_ON();
			Delay_ms(LED_BLINK_300ms);
			LED2_OFF();

			usart6_send(rs485_tx_array, sizeof(rs485_tx_array));	// send this byte back


		}

	}	// while(1)
}	// main()

/*************************** End of file ****************************/
