#ifndef EXTI_H
#define EXTI_H

#include "../Device Header/stm32f103x8.h"
#include "gpio.h"
#include "../UTIL/bitwise.h"

typedef struct{
    uint8_t port    ;       //Selects the port
                            //Can take values of @ref EXTI_PORTS

    uint8_t pinNo     ;     //Select the pin number
                            //Takes values from @ref GPIO_PINS

    uint8_t edgeSense;      //Select Rising edge or Falling edge or both
                            //Takes values from @ref EXTI_EDGES

    uint8_t enable;         //Select Enable or Disable the interrupt
                            //Takes values from @ref EXTI_EN

    void (*callBack)(void); //the callback function to be called when interrupt happens
    
} EXTI_config_t;

/* @ref EXTI_EDGES
    0: Falling Edge
    1: Rising Edge
    2: Both Edges
    3: Clear Both
*/

#define FALLING_EDGE 0
#define RISING_EDGE  1
#define BOTH_EDGES   2
#define RESET_EDGES  3


/* @ref EXTI_EN
    0: Disable
    1: Enable
*/

#define ENABLE 1
#define DISABLE 0

/* @ref EXTI_PORTS
    0: PORTA
    1: PORTB
    2: PORTC
    3: PORTD
    4: PORTE
*/

#define EXTI_GPIOA 0
#define EXTI_GPIOB 1
#define EXTI_GPIOC 2
#define EXTI_GPIOD 3
#define EXTI_GPIOE 4

/**================================================================
* @Fn - EXTI_init
* @brief - Initialize the EXTI line selected with the parameters in config variable
* @param [in]: config - Pointer to config structure which has the desired config parameters, Refer to User Type Definitions Section
* @retval - None
*/
void EXTI_init(EXTI_config_t* config);

/**================================================================
* @Fn - EXTI_deInit
* @brief - RESET all EXTI registers to reset values
* @retval - None
*/
void EXTI_deInit(void);

/**================================================================
* @Fn - EXTI_init
* @brief - UPDATE the EXTI line selected with the parameters in config variable
* @param [in]: config - Pointer to config structure which has the desired config parameters, Refer to User Type Definitions Section
* @retval - None
*/
void EXTI_update(EXTI_config_t* config);



#endif