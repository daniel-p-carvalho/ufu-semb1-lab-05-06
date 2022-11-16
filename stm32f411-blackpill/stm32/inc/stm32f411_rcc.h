/****************************************************************************
 * stm32/inc/stm32f411_rcc.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32f411_memmap.h"

#ifndef __STM32_INC_STM32F411_RCC_H
#define __STM32_INC_STM32F411_RCC_H

 /****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Offsets *********************************************************/

#define STM32_RCC_AHB1ENR_OFFSET  0x0030   /* AHB1 Peripheral Clock enable register */

/* Register Addresses *******************************************************/

#define STM32_RCC_AHB1ENR        (STM32_RCC_BASE+STM32_RCC_AHB1ENR_OFFSET)

/* AHB1 Peripheral Clock enable register */

#define RCC_AHB1ENR_GPIOAEN      (1 << 0)  /* Bit 0:  IO port A clock enable */
#define RCC_AHB1ENR_GPIOBEN      (1 << 1)  /* Bit 1:  IO port B clock enable */
#define RCC_AHB1ENR_GPIOCEN      (1 << 2)  /* Bit 2:  IO port C clock enable */

#endif /* __STM32_INC_STM32F411_RCC_H */