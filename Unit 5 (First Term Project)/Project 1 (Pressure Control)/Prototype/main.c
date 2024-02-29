#include "AlarmController.h"
#include "PController.h"
#include "PSensorDriver.h"

void setup(void){
    AControllerSetup();
    PControllerSetup();
    PSensorSetup();
    printf("\n");
}

int main(){
    char dummy;
    setup();
    while(1){
        PSensorCurrState();
        PControllerCurrState();
        AControllerCurrState();
        printf("\nPress Enter to continue:\n");
        scanf("%c",&dummy);
        fflush(stdin);
    }
}