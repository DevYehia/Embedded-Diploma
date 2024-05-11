//-----------------------------
//Includes
#include "stm32f103x8.h"
//-----------------------------


//-----------------------------
//User type definitions (structures)
typedef struct{
    uint8_t pinNo;    //the pin number to be configured
                      //can take value of @ref GPIO_PINS

    uint8_t pinMode;  //The mode of the pin (i/p push-pull, o/p open drain. etc..)
                      //can take value of @ref GPIO_MODES

    uint8_t pinSpeed; //The output speed of the pin
                      //can take value of @ref GPIO_SPEEDS
} GPIO_config_t;
//-----------------------------


//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref GPIO_LOGIC
    0: LOGIC_LOW
    1: LOGIC_HIGH
*/
#define LOGIC_LOW 0
#define LOGIC_HIGH 1
/*@ref GPIO_PINS
    x: PINx
*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15
/*@ref GPIO_MODES
    0: o/p Push-Pull
    1: o/p Open-Drain
    2: Alt. o/p Push-Pull
    3: Alt. o/p Open-Drain
    4: i/p Analog
    5: i/p Floating
    6: i/p Pull-Down
    7: i/p Pull-Up
*/
#define O_PUSH_PULL         0
#define O_OPEN_DRAIN        1
#define O_ALT_PUSH_PULL     2
#define O_ALT_OPEN_DRAIN    3
#define I_ANALOG            4
#define I_FLOATING          5
#define I_PULL_DOWN         6
#define I_PULL_UP           7
/*@ref GPIO_SPEEDS
    1: 10 MHz
    2: 2 MHz
    3: 50 MHz
*/
#define MAX_10_MHZ 1
#define MAX_2_MHZ  2
#define MAX_50_MHZ 3
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

/**================================================================
* @Fn - GPIO_init
* @brief - Initialize a pin of a GPIO port to any of the input or output modes
* @param [in]: GPIOx - Pointer to the GPIO port that will be initialized (x : A...E)
* @param [in]: config - Pointer to config structure which has the desired config parameters, Refer to User Type Definitions Section
* @retval - None
*/
void GPIO_init(GPIO_t* GPIOx,GPIO_config_t* config);

/**================================================================
* @Fn - GPIO_deInit
* @brief - Resets all GPIO Registers to reset value
* @param [in]: GPIOx - Pointer to the GPIO port that will be de-initialized (x : A...E)
* @retval - None
*/
void GPIO_deInit(GPIO_t* GPIOx);


/**================================================================
* @Fn - GPIO_read_pin
* @brief - Reads the value on a pin
* @param [in]: GPIOx - Pointer to the GPIO port that will be read from (x : A...E)
* @param [in]: pinNo - The pin number to be read. Takes value from @ref GPIO_PINS
* @retval - Takes value form @ref GPIO_LOGIC
*/
uint8_t GPIO_read_pin(GPIO_t* GPIOx, uint8_t pinNo);

/**================================================================
* @Fn - GPIO_read_port
* @brief - Reads the value on the entire port
* @param [in]: GPIOx - Pointer to the GPIO port that will be read from (x : A...E)
* @retval - A 16-bit integer representing the port values
*/
uint16_t GPIO_read_port(GPIO_t* GPIOx);


/**================================================================
* @Fn - GPIO_write_pin
* @brief - writes the value on a pin
* @param [in]: GPIOx - Pointer to the GPIO port that will be written onto (x : A...E)
* @param [in]: pinNo - The pin number to be written onto. Takes value from @ref GPIO_PINS
* @param [in]: value - The value that will be written. Takes value from @ref GPIO_LOGIC
* @retval - None
*/
void GPIO_write_pin(GPIO_t* GPIOx, uint8_t pinNo, uint8_t value);

/**================================================================
* @Fn - GPIO_write_port
* @brief - writes the value on the entire port
* @param [in]: GPIOx - Pointer to the GPIO port that will be written onto (x : A...E)
* @param [in]: value - The value that will be written.
* @retval - None
*/
void GPIO_write_port(GPIO_t* GPIOx, uint16_t value);


/**================================================================
* @Fn - GPIO_toggle_pin
* @brief - toggles the value on a pin
* @param [in]: GPIOx - Pointer to the GPIO port (x : A...E)
* @param [in]: pinNo - The pin number to be toggled. Takes value from @ref GPIO_PINS
* @retval - None
*/
void GPIO_toggle_pin(GPIO_t* GPIOx, uint8_t pinNo);

/**================================================================
* @Fn - GPIO_lock_pin
* @brief - locks the config register bits of a pin
* @param [in]: GPIOx - Pointer to the GPIO port (x : A...E)
* @param [in]: pinNo - The pin number to be locked. Takes value from @ref GPIO_PINS
* @retval - None
*/
void GPIO_lock_pin(GPIO_t* GPIOx, uint8_t pinNo);
