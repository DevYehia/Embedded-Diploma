#include <stdio.h>
#include <string.h>
int main(){
    char str[200];
    char x;
    printf("Enter a string: ");
    gets(str);
    printf("The reverse is: ");
    for(int i = strlen(str) - 1 ; i >= 0 ; i--){
        printf("%c",str[i]);
    }

}