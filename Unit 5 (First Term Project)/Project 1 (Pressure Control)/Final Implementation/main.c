#include "APP/AlarmController.h"
#include "APP/PController.h"
#include "APP/PSensorDriver.h"
#include "DRIVER/driver.h"

void setup(void){
    AControllerSetup();
    PControllerSetup();
    PSensorSetup();
}

int main(){
    GPIO_INITIALIZATION();
    setup();
    while(1){
        PSensorCurrState();
        PControllerCurrState();
        AControllerCurrState();
    }
}