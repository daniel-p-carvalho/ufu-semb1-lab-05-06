/****************************************************************************
 * bsp/inc/bsp.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __BSP_INC_BSP_H
#define __BSP_INC_BSP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: bsp_init
 * 
 * Description: Initialize and configure microcontrollers clock and 
 *              peripherals. This function should be called before aplication
 *              entry point.
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *    bsp_init()
 *   
 ****************************************************************************/

void bsp_init(void);

#endif /* __BSP_INC_BSP_H */