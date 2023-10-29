#include <stdio.h>

int main(){
    char x;
    printf("Enter a character: ");
    fflush(stdout);
    scanf("%c",&x);
    printf("The ASCII value of %c is: %d",x,x);

}