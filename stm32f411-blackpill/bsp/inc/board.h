/****************************************************************************
 * bsp/inc/board.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __BSP_INC_BOARD_H
#define __BSP_INC_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32_gpio.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MAX_DIGITAL_IO  16

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Board pin definitions ****************************************************/

static const int digitalPins[MAX_DIGITAL_IO] =
{
  GPIO_PORTC | GPIO_PIN13, /* D0 - Not compatible with Arduino */
  GPIO_PORTA | GPIO_PIN0,  /* D1 - Not compatible with Arduino*/
  GPIO_PORTA | GPIO_PIN10, /* D2 */
  GPIO_PORTB | GPIO_PIN3,  /* D3 */
  GPIO_PORTB | GPIO_PIN5,  /* D4 */
  GPIO_PORTB | GPIO_PIN4,  /* D5 */
  GPIO_PORTB | GPIO_PIN10, /* D6 */
  GPIO_PORTA | GPIO_PIN8,  /* D7 */
  GPIO_PORTA | GPIO_PIN9,  /* D8 */
  0,                       /* D9 */
  GPIO_PORTB | GPIO_PIN6,  /* D10 */
  GPIO_PORTA | GPIO_PIN7,  /* D11 */
  GPIO_PORTA | GPIO_PIN6,  /* D12 */
  GPIO_PORTA | GPIO_PIN5,  /* D13 */
  GPIO_PORTB | GPIO_PIN9,  /* D14 */
  GPIO_PORTB | GPIO_PIN8   /* D15 */
};

#endif /* __BSP_INC_BOARD_H */