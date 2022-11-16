/****************************************************************************
 * stm32/src/stm32_gpio.c
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include "stm32_gpio.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define getreg32(a)     (*(volatile uint32_t *)(a))
#define putreg32(v,a)   (*(volatile uint32_t *)(a) = v)

/****************************************************************************
 * Private Data
 ****************************************************************************/

static const uint32_t g_gpiobase[] =
{
  STM32_GPIOA_BASE,
  STM32_GPIOB_BASE,
  STM32_GPIOC_BASE,
  STM32_GPIOD_BASE,
  STM32_GPIOE_BASE,
  0,
  0,
  STM32_GPIOH_BASE
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_gpio_read
 ****************************************************************************/

bool stm32_gpio_read(uint32_t pinset)
{
  return false;
}

/****************************************************************************
 * Name: stm32_gpio_write
 ****************************************************************************/

void stm32_gpio_write(uint32_t pinset, bool value)
{
  uint32_t port;
  uint32_t pin;
  uint32_t bit_offset;
  uint32_t base_address;

  pin  = (pinset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;
  port = (pinset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;

  /* Testes de verificacao de consistencia */

  //TODO: verificar se o microcontrolador possui a porta e o pino especificado

  base_address = g_gpiobase[port];

  if (value)
    {
      bit_offset = GPIO_BSRR_SET(pin);
    }
  else
    {
      bit_offset = GPIO_BSRR_RESET(pin);
    }

  putreg32(bit_offset, base_address + STM32_GPIO_BSRR_OFFSET);
}

/****************************************************************************
 * Name: stm32_gpio_config
 ****************************************************************************/

int stm32_gpio_config(uint32_t configset)
{
  uint32_t pin;
  uint32_t port;
  uint32_t regval;

  uint32_t pin_mode;
  uint32_t pin_setting;
  uint32_t base_address;

  pin = (configset & GPIO_PIN_MASK) >> GPIO_PIN_SHIFT;
  port = (configset & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;

  /* Testes de verificacao de consistencia */

  //TODO: verificar se o microcontrolador possui a porta e o pino especificado
  //TODO: Desabilitar interrupcoes

  base_address = g_gpiobase[port];

  /* Configurar pin mode */

  switch (configset & GPIO_MODE_MASK)
    {
      case GPIO_INPUT:
        pin_mode = GPIO_MODER_INPUT;
        break;

      case GPIO_OUTPUT:
        pin_mode = GPIO_MODER_OUTPUT;
        break;
      
      case GPIO_ALT:        /* Nao suportado */
        return -1;
        break;

      case GPIO_ANALOG:     /* Nao suportado */
        return -1;
        break;

      default:
        return -1;
        break;
    }

  regval = getreg32(base_address + STM32_GPIO_MODER_OFFSET);
  regval &= ~GPIO_MODER_MASK(pin);
  regval |= ((uint32_t)pin_mode << GPIO_MODER_SHIFT(pin));
  putreg32(regval, base_address + STM32_GPIO_MODER_OFFSET);

  /* Configura tipo da saida PP/OD */

  regval = getreg32(base_address + STM32_GPIO_OTYPER_OFFSET);
  pin_setting = GPIO_OTYPER_OD << GPIO_OT_SHIFT(pin);

  if ((pin_mode == GPIO_MODER_OUTPUT || pin_mode == GPIO_MODER_ALT) &&
      (configset & GPIO_OPENDRAIN) != 0)
    {
      regval |= pin_setting; 
    }
  else
    {
      regval &= ~pin_setting;
    }
  putreg32(regval, base_address + STM32_GPIO_OTYPER_OFFSET);  

  /* Configura resistores de Pull-up/Pull-down */

  if (pin_mode != GPIO_MODER_ANALOG)
    {
      switch (configset & GPIO_PUPD_MASK)
        {
      
          default:
          case GPIO_FLOAT:    /* No pull-up, pull-down */
            pin_setting = GPIO_PUPDR_NONE;
            break;
      
          case GPIO_PULLUP:
            pin_setting = GPIO_PUPDR_PULLUP;
            break;
      
          case GPIO_PULLDOWN:
            pin_setting = GPIO_PUPDR_PULLDOWN;
            break;
      
      }
    }
  regval = getreg32(base_address + STM32_GPIO_PUPDR_OFFSET);
  regval &= ~GPIO_PUPDR_MASK(pin);
  regval |= ((uint32_t)pin_setting << GPIO_PUPDR_SHIFT(pin));
  putreg32(regval, base_address + STM32_GPIO_PUPDR_OFFSET);

  return 0;
}
