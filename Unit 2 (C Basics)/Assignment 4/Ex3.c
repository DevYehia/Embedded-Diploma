#include <stdio.h>
#include <string.h>

void reverseString(char str[], int size,int index){
    if(index >= size/2) //reached middle of string or passed it
        return;
    char tmp = str[index];
    str[index] = str[size - 1 - index];
    str[size - 1 - index] = tmp;
    reverseString(str,size,index+1);
}

int main(){
    char str[101];
    printf("Please Enter a sentence(Max 100 words): ");
    gets(str);
    reverseString(str,strlen(str),0);
    printf("Reverse is %s",str);
}