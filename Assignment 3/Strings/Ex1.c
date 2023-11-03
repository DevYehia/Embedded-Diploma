#include <stdio.h>

int main(){
    char str[200];
    char x;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a charcter to find frequency: ");
    scanf("%c",&x);
    int freq = 0;
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] == x)
            freq++;
    }
    printf("frequency of %c is %d",x,freq);
}