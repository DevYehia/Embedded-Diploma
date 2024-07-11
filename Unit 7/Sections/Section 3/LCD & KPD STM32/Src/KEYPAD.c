#include "KEYPAD.h"

uint8_t symbols[ROW_SIZE][COL_SIZE] = {
    {'/','9','8','7'},
    {'*','6','5','4'},
    {'-','3','2','1'},
    {'+','=','0','C'}
};

uint8_t keypad_rows[ROW_SIZE] = {R0, R1, R2, R3};
uint8_t keypad_cols[COL_SIZE] = {C0, C1, C2, C3};
void KEYPAD_init(void){
    //configure all rows as input pull up
    for(uint8_t i = 0 ; i < ROW_SIZE ; i++){
        GPIO_config_t conf = {keypad_rows[i],I_PULL_UP,MAX_10_MHZ};
        GPIO_init(ROW_PORT, &conf);
    }
    //configure all cols as output open drain all initially at LOGIC LOW
    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
        GPIO_config_t conf = {keypad_cols[i],O_PUSH_PULL,MAX_10_MHZ};
        GPIO_init(COL_PORT, &conf);
        GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_LOW);
    }
}


uint8_t KEYPAD_read(void){

    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
        GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_LOW);
    }
    uint8_t nonePressed = 1;
    for(uint8_t i = 0 ; i < ROW_SIZE ; i++){
        if(GPIO_read_pin(ROW_PORT,keypad_rows[i]) == LOGIC_LOW){
            nonePressed = 0;
            break;
        }
    }
    if(nonePressed){
        return '?';
    }

    //make all cols open circuit
    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
        GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_HIGH);
    }    

    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
        GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_LOW);
        for(uint8_t j = 0 ; j < ROW_SIZE ; j++){
            if(GPIO_read_pin(ROW_PORT,keypad_rows[j]) == LOGIC_LOW){
                while(GPIO_read_pin(ROW_PORT,keypad_rows[j]) == LOGIC_LOW);
                //make all cols LOGIC_LOW
                return symbols[j][i];
            }
        }
        GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_HIGH);
    }


    //shouldn't reach here
    return '?';


}