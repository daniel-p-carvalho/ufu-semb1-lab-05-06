/****************************************************************************
 * hal/inc/digital_io.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __HAL_INC_DIGITAL_IO_H
#define __HAL_INC_DIGITAL_IO_H

 /****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

enum e_digital_io_state
{
  LOW = 0,
  HIGH
};

enum e_digital_io_mode
{
  INPUT = 0,
  INPUT_PULLUP,
  OUTPUT
};

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: digitalRead
 * 
 * Description: Reads the value from a specified digital pin, either HIGH or
 *              LOW.
 * 
 * Params:  
 *   pin: the Arduino pin number to set the mode of.
 * 
 * Return:
 *   HIGH or LOW
 * 
 * Syntax:
 *    digitalRead(pin)
 *   
 ****************************************************************************/

int digitalRead(int pin);

/****************************************************************************
 * Name: digitalWrite
 * 
 * Description: Write a HIGH or a LOW value to a digital pin.
 * 
 * Params:  
 *   pin  : the Arduino pin number to set the mode of.
 *   value: HIGH or LOW.
 * 
 * Return:
 * 
 * Syntax:
 *    digitalWrite(pin, value)
 *   
 ****************************************************************************/

void digitalWrite(int pin, int value);

/****************************************************************************
 * Name: pinMode
 * 
 * Description: Configures the specified pin to behave either as an input or
 * an output. See the Digital Pins page for details on the functionality of 
 * the pins.
 * 
 * Params:  
 *   pin: the Arduino pin number to set the mode of.
 *   mode: INPUT, OUTPUT, or INPUT_PULLUP. See the Digital Pins page for a
 *         more complete description of the functionality.
 * 
 * Return:
 * 
 * Syntax:
 *    pinMode(pin, mode)
 *   
 ****************************************************************************/

void pinMode(int pin, int mode);

#endif /* __HAL_INC_DIGITAL_IO_H */