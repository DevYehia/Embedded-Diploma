#include <stdio.h>

int main(){
    char str[200];
    char x;
    printf("Enter a string: ");
    gets(str);
    int length = 0;
    for(int i = 0 ; str[i] != '\0' ; i++){
        length++;
    }
    printf("Length of string is %d",length);
}