/****************************************************************************
 * stm32/inc/stm32f411_memmap.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#ifndef __STM32_INC_STM32F411_MEMMAP_H
#define __STM32_INC_STM32F411_MEMMAP_H

 /****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* AHB1 Base Addresses ******************************************************/

#define STM32_RCC_BASE       0x40023800     /* 0x40023800-0x40023bff: Reset and Clock control RCC */

/* GPIO Base Addresses ******************************************************/

#define STM32_GPIOA_BASE     0x40020000     /* 0x40020000-0x400203ff GPIO Port A */
#define STM32_GPIOB_BASE     0x40020400     /* 0x40020400-0x400207ff GPIO Port B */
#define STM32_GPIOC_BASE     0x40020800     /* 0x40020800-0x40020bff GPIO Port C */
#define STM32_GPIOD_BASE     0x40020c00     /* 0x40020c00-0x40020fff GPIO Port D */
#define STM32_GPIOE_BASE     0x40021000     /* 0x40021000-0x400213ff GPIO Port E */
#define STM32_GPIOH_BASE     0x40021c00     /* 0x40021c00-0x40021fff GPIO Port H */

#endif /* __STM32_INC_STM32F411_MEMMAP_H */