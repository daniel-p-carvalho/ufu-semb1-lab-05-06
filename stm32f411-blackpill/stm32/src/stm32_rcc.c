/****************************************************************************
 * stm32/stm32f411_rcc.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdint.h>

#include "stm32_rcc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define getreg32(a)     (*(volatile uint32_t *)(a));
#define putreg32(v,a)   (*(volatile uint32_t *)(a) = v);

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: rcc_enableahb1
 ****************************************************************************/

void stm32_rcc_enableahb1(void)
{
  uint32_t regval;

  regval = getreg32(STM32_RCC_AHB1ENR);

  /* GPIO's clock enable */

#ifdef CONFIG_STM32_GPIOA_EN
  regval |= (RCC_AHB1ENR_GPIOAEN);
#endif
#ifdef CONFIG_STM32_GPIOB_EN
  regval |= (RCC_AHB1ENR_GPIOBEN);
#endif
#ifdef CONFIG_STM32_GPIOC_EN
  regval |= (RCC_AHB1ENR_GPIOCEN);
#endif
#ifdef CONFIG_STM32_GPIOD_EN
  regval |= (RCC_AHB1ENR_GPIODEN);
#endif
#ifdef CONFIG_STM32_GPIOE_EN
  regval |= (RCC_AHB1ENR_GPIOEEN);
#endif
#ifdef CONFIG_STM32_GPIOH_EN
  regval |= (RCC_AHB1ENR_GPIOHEN);
#endif

  /* CRC clock enable */

#ifdef CONFIG_STM32_CRC
  regval |= RCC_AHB1ENR_CRCEN;
#endif

  /* DMA 1 clock enable */

#ifdef CONFIG_STM32_DMA1
  regval |= RCC_AHB1ENR_DMA1EN;
#endif

  /* DMA 2 clock enable */

#ifdef CONFIG_STM32_DMA2
  regval |= RCC_AHB1ENR_DMA2EN;
#endif

  putreg32(regval, STM32_RCC_AHB1ENR);
}