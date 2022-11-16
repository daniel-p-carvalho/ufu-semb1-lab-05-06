/****************************************************************************
 * hal/src/digital_io.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "board.h"
#include "digital_io.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: digitalRead   
 ****************************************************************************/

int digitalRead(int pin)
{
  int pin_value;

  /* Consistency checks */

  if ((pin < 0) || (pin >= MAX_DIGITAL_IO))
    {
      /* Do nothing */

      return 0;
    }

  if (pin == 9)
    
    {
      /* Do nothing */

      return 0;
    }

  pin_value = digitalPins[pin];

  return stm32_gpio_read(pin_value) ? HIGH : LOW;
}

/****************************************************************************
 * Name: digitalWrite   
 ****************************************************************************/

void digitalWrite(int pin, int value)
{
  int pin_value;

  /* Consistency checks */

  if ((pin < 0) || (pin >= MAX_DIGITAL_IO))
    {
      /* Do nothing */

      return;
    }

  if (pin == 9)
    
    {
      /* Do nothing */

      return;
    }

  pin_value = digitalPins[pin];
  stm32_gpio_write(pin_value, value);  
}

/****************************************************************************
 * Name: pinMode   
 ****************************************************************************/

void pinMode(int pin, int mode)
{
  int pin_value;
  int pin_mode;

  /* Consistency checks */

  if ((pin < 0) || (pin >= MAX_DIGITAL_IO))
    {
      /* Do nothing */

      return;
    }

  if (pin == 9)    
    {
      /* Do nothing */

      return;
    }

  pin_value = digitalPins[pin];

  pin_mode = 0;
  switch (mode)
    {
      case INPUT_PULLUP:
        pin_mode |= (GPIO_INPUT | GPIO_PULLUP);

      case INPUT:
        pin_mode |= GPIO_INPUT;
        break;

      case OUTPUT:
        pin_mode |= (GPIO_OUTPUT | GPIO_PUSHPULL);
        break;

      default:
        /* Do nothing */

        return;
    }

  stm32_gpio_config(pin_value | pin_mode);
}