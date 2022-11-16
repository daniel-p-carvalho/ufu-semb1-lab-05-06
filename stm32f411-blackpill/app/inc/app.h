/****************************************************************************
 * app/src/app.h
 *
 *   Authors: Daniel Pereira de Carvalho <daniel.carvalho@ufu.br>
 *            Marcelo Barros de Almeida  <marcelo.barros@ufu.br>
 *
 ****************************************************************************/

#ifndef __APP_INC_APP_H
#define __APP_INC_APP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: setup
 * 
 * Description: The setup() function is called when a sketch starts. Use it
 *              to initialize variables, pin modes, start using libraries,
 *              etc. The setup() function will only run once, after each 
 *              powerup or reset of the board.
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *    setup()
 *   
 ****************************************************************************/

void setup(void);

/****************************************************************************
 * Name: loop
 * 
 * Description: After creating a setup() function, which initializes and sets
 *              the initial values, the loop() function does precisely what
 *              its name suggests, and loops consecutively, allowing your
 *              program to change and respond. Use it to actively control the
 *              board.
 * 
 * Params:
 * 
 * Return:
 * 
 * Syntax:
 *    loop()
 *   
 ****************************************************************************/

void loop(void);

#endif /* __APP_INC_APP_H */