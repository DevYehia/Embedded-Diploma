#include <stdio.h>

int main(){
    char x,lower;
    printf("Enter an alphabet: ");
    fflush(stdout);
    scanf("%c",&x);
    if(x < 'a'){
        lower = x + 32; //turn letter to lowercase if it is uppercase
    }
    else{
        lower = x;
    }
    switch(lower){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            printf("%c is a vowel",x);
        }
        break;
        default:
            printf("%c is a consonant",x);
    }
}