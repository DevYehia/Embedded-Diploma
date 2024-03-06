#include "util.h"

void safeInput(char *inp , unsigned int maxLimit){
    char c;
    unsigned int i;
    for(i = 0 ; i < maxLimit ; i++){
        c = getchar();
        if(c == '\n')
            break;
        inp[i] = c;
    }
    inp[i] = '\0';
}