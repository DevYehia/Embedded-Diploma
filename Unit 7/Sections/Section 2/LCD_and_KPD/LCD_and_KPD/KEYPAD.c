#include "KEYPAD.h"

uint8_t symbols[ROW_SIZE][COL_SIZE] = {
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};

uint8_t keypad_rows[ROW_SIZE] = {R0, R1, R2, R3};
uint8_t keypad_cols[COL_SIZE] = {C0, C1, C2, C3};
void KEYPAD_init(void){
    //configure all rows as input pull up
    for(uint8_t i = 0 ; i < ROW_SIZE ; i++){
       // GPIO_config_t conf = {keypad_rows[i],I_PULL_UP,MAX_10_MHZ};
		CLR_BIT(ROW_DIR,keypad_rows[i]);
		SET_BIT(ROW_PORT,keypad_rows[i]);
    }
    //configure all cols as output open drain all initially at LOGIC LOW
    for(uint8_t i = 0 ; i < COL_SIZE ; i++){

		SET_BIT(COL_DIR,keypad_cols[i]);
		CLR_BIT(COL_PORT,keypad_cols[i]);		
    }
}


uint8_t KEYPAD_read(void){

    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
        //GPIO_write_pin(COL_PORT,keypad_cols[i],LOGIC_LOW);
		CLR_BIT(COL_PORT,keypad_cols[i]);		
    }
    uint8_t nonePressed = 1;
    for(uint8_t i = 0 ; i < ROW_SIZE ; i++){
        //if(GPIO_read_pin(ROW_PORT,keypad_rows[i]) == LOGIC_LOW){
		  if(GET_BIT(ROW_PIN,keypad_rows[i]) == 0){
            nonePressed = 0;
            break;
        }
    }
    if(nonePressed){
        return '?';
    }

    //make all cols open circuit
    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
		SET_BIT(COL_PORT,keypad_cols[i]);	
    }    

    for(uint8_t i = 0 ; i < COL_SIZE ; i++){
		CLR_BIT(COL_PORT,keypad_cols[i]);		
        for(uint8_t j = 0 ; j < ROW_SIZE ; j++){
            if(GET_BIT(ROW_PIN,keypad_rows[j]) == 0){
                while(GET_BIT(ROW_PIN,keypad_rows[j]) == 0);
				
                //make all cols LOGIC_LOW
                return symbols[j][i];
            }
        }
		SET_BIT(COL_PORT,keypad_cols[i]);	
    }


    //shouldn't reach here
    return '?';


}