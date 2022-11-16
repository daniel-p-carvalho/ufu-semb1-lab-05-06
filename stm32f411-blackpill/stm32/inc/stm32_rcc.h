/****************************************************************************
 * stm32/inc/stm32_rcc.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32_RCC_H
#define __STM32_INC_STM32_RCC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "config.h"

#if defined (CONFIG_STM32F411)
#  include "stm32f411_rcc.h"
#else
#  error "Microcontroller not supportted by this driver"
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: rcc_enableahb1
 * 
 * Description: Enable selected AHB1 peripherals. See config.h
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *   
 ****************************************************************************/

void stm32_rcc_enableahb1(void);

#endif /* __STM32_INC_STM32_RCC_H */