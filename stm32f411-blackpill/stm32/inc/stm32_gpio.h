/****************************************************************************
 * stm32/inc/stm32_gpio.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __STM32_INC_STM32_GPIO_H
#define __STM32_INC_STM32_GPIO_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdbool.h>
#include <stdint.h>

#include "config.h"

#if defined (CONFIG_STM32F411)
#  include "stm32f411_gpio.h"
#else
#  error "Microcontroller not supportted by this driver"
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/*
 * Bits  0 -  3: GPIO number: 0-15
 * Bits  4 -  7: Port number
 * Bits  8 -  9: GPIO port mode
 * Bit       10: Output type 0 = Push-pull 1 = Open-drain
 * Bits 11 - 12: GPIO speed
 * Bits 13 - 14: Pull-up/pull down
 * Bits 15 - 18: Alternate function
 */


#define GPIO_PIN_SHIFT          0
#define GPIO_PIN_MASK           (15 << GPIO_PIN_SHIFT)
#define GPIO_PIN0               ( 0 << GPIO_PIN_SHIFT)
#define GPIO_PIN1               ( 1 << GPIO_PIN_SHIFT)
#define GPIO_PIN2               ( 2 << GPIO_PIN_SHIFT)
#define GPIO_PIN3               ( 3 << GPIO_PIN_SHIFT)
#define GPIO_PIN4               ( 4 << GPIO_PIN_SHIFT)
#define GPIO_PIN5               ( 5 << GPIO_PIN_SHIFT)
#define GPIO_PIN6               ( 6 << GPIO_PIN_SHIFT)
#define GPIO_PIN7               ( 7 << GPIO_PIN_SHIFT)
#define GPIO_PIN8               ( 8 << GPIO_PIN_SHIFT)
#define GPIO_PIN9               ( 9 << GPIO_PIN_SHIFT)
#define GPIO_PIN10              (10 << GPIO_PIN_SHIFT)
#define GPIO_PIN11              (11 << GPIO_PIN_SHIFT)
#define GPIO_PIN12              (12 << GPIO_PIN_SHIFT)
#define GPIO_PIN13              (13 << GPIO_PIN_SHIFT)
#define GPIO_PIN14              (14 << GPIO_PIN_SHIFT)
#define GPIO_PIN15              (15 << GPIO_PIN_SHIFT)

#define GPIO_PORT_SHIFT         4
#define GPIO_PORT_MASK          (15 << GPIO_PORT_SHIFT)
#define GPIO_PORTA              (0 << GPIO_PORT_SHIFT)     /* GPIOA */
#define GPIO_PORTB              (1 << GPIO_PORT_SHIFT)     /* GPIOB */
#define GPIO_PORTC              (2 << GPIO_PORT_SHIFT)     /* GPIOC */
#define GPIO_PORTD              (3 << GPIO_PORT_SHIFT)     /* GPIOD */
#define GPIO_PORTE              (4 << GPIO_PORT_SHIFT)     /* GPIOE */
#define GPIO_PORTF              (5 << GPIO_PORT_SHIFT)     /* GPIOF */
#define GPIO_PORTG              (6 << GPIO_PORT_SHIFT)     /* GPIOG */
#define GPIO_PORTH              (7 << GPIO_PORT_SHIFT)     /* GPIOH */

#define GPIO_MODE_SHIFT         (8)
#define GPIO_MODE_MASK          (3 << GPIO_MODE_SHIFT)
#define GPIO_INPUT              (0 << GPIO_MODE_SHIFT)     /* Input mode */
#define GPIO_OUTPUT             (1 << GPIO_MODE_SHIFT)     /* General purpose output mode */
#define GPIO_ALT                (2 << GPIO_MODE_SHIFT)     /* Alternate function mode */
#define GPIO_ANALOG             (3 << GPIO_MODE_SHIFT)     /* Analog mode */

#define GPIO_OPENDRAIN          (1 << 10)                  /* 1 = Open-drain output */
#define GPIO_PUSHPULL           (0)                        /* 0 = Push-pull output */

#define GPIO_SPEED_SHIFT        (11)
#define GPIO_SPEED_MASK         (3 << GPIO_SPEED_SHIFT)
#define GPIO_SPEED_LOW          (0 << GPIO_SPEED_SHIFT)    /* Low speed output */
#define GPIO_SPEED_MEDIUM       (1 << GPIO_SPEED_SHIFT)    /* Medium speed output */
#define GPIO_SPEED_FAST         (2 << GPIO_SPEED_SHIFT)    /* Fast speed output */
#define GPIO_SPEED_HIGH         (3 << GPIO_SPEED_SHIFT)    /* High speed output */

#define GPIO_PUPD_SHIFT         (13)
#define GPIO_PUPD_MASK          (3 << GPIO_PUPD_SHIFT)
#define GPIO_FLOAT              (0 << GPIO_PUPD_SHIFT)     /* No pull-up, pull-down */
#define GPIO_PULLUP             (1 << GPIO_PUPD_SHIFT)     /* Pull-up */
#define GPIO_PULLDOWN           (2 << GPIO_PUPD_SHIFT)     /* Pull-down */

#define GPIO_AF_SHIFT           (14)
#define GPIO_AF_MASK            (15 << GPIO_AF_SHIFT)
#define GPIO_AF(n)              ((n) << GPIO_AF_SHIFT)
#define GPIO_AF0                (0 << GPIO_AF_SHIFT)
#define GPIO_AF1                (1 << GPIO_AF_SHIFT)
#define GPIO_AF2                (2 << GPIO_AF_SHIFT)
#define GPIO_AF3                (3 << GPIO_AF_SHIFT)
#define GPIO_AF4                (4 << GPIO_AF_SHIFT)
#define GPIO_AF5                (5 << GPIO_AF_SHIFT)
#define GPIO_AF6                (6 << GPIO_AF_SHIFT)
#define GPIO_AF7                (7 << GPIO_AF_SHIFT)
#define GPIO_AF8                (8 << GPIO_AF_SHIFT)
#define GPIO_AF9                (9 << GPIO_AF_SHIFT)
#define GPIO_AF10               (10 << GPIO_AF_SHIFT)
#define GPIO_AF11               (11 << GPIO_AF_SHIFT)
#define GPIO_AF12               (12 << GPIO_AF_SHIFT)
#define GPIO_AF13               (13 << GPIO_AF_SHIFT)
#define GPIO_AF14               (14 << GPIO_AF_SHIFT)
#define GPIO_AF15               (15 << GPIO_AF_SHIFT)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_gpio_read
 * 
 * Description:
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *   
 ****************************************************************************/

bool stm32_gpio_read(uint32_t pinset);

/****************************************************************************
 * Name: stm32_gpio_write
 * 
 * Description:
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *   
 ****************************************************************************/

void stm32_gpio_write(uint32_t pinset, bool value);

/****************************************************************************
 * Name: stm32_gpio_config
 * 
 * Description:
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *   
 ****************************************************************************/

int stm32_gpio_config(uint32_t configset);

#endif /* __STM32_INC_STM32_GPIO_H */