#include <stdio.h>

int main(){
    char x;
    printf("Enter a chracter: ");
    scanf("%c",&x);
    if( (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') ){
        printf("%c is an alphabet",x);
    }
    else{
        printf("%c is not an alphabet",x);        
    }
}