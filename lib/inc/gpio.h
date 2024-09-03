#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"

#define LED1_PORT	GPIOE
#define LED2_PORT	GPIOE
#define LED3_PORT	GPIOE

#define LED1_PIN_NUM	13
#define LED2_PIN_NUM	14
#define LED3_PIN_NUM	15

//#define BTN_CHECK_MS			10
//#define	BTN_PRESS_CNT			4 


#define LED1_ON()		(LED1_PORT -> BSRR |= 1 << (LED1_PIN_NUM + 16))
#define LED2_ON()		(LED2_PORT -> BSRR |= 1 << (LED2_PIN_NUM + 16))
#define LED3_ON()		(LED3_PORT -> BSRR |= 1 << (LED3_PIN_NUM + 16))

#define LED1_OFF()		(LED1_PORT -> BSRR |= 1 << LED1_PIN_NUM)
#define LED2_OFF()		(LED2_PORT -> BSRR |= 1 << LED2_PIN_NUM)
#define LED3_OFF()		(LED3_PORT -> BSRR |= 1 << LED3_PIN_NUM)

#define LED1_TOGGLE()	(LED1_PORT -> ODR ^= (1 << LED1_PIN_NUM))
#define LED2_TOGGLE()	(LED2_PORT -> ODR ^= (1 << LED2_PIN_NUM))
#define LED3_TOGGLE()	(LED3_PORT -> ODR ^= (1 << LED3_PIN_NUM))


void GPIO_Init(void);

#endif