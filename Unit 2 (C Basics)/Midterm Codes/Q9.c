#include <stdio.h>
#include <string.h>
void reverseWords(char str[],int size){

    for(int i = size - 1 ; i >= 0 ; i--){ //traverse string in reverse order until space is found

        if(str[i] == ' '){ //if space is found, do forward traversing till next space or end of string

            for(int j = i+1 ; str[j] != ' ' && str[j] != '\0' ; j++){
                printf("%c",str[j]);
            }
            printf(" ");
        }
    }
    for(int i = 0 ; str[i] != ' ' && str[i] != '\0' ; i++){ //print first word of the string
        printf("%c",str[i]); 
    }
    
}
int main(){
    char str[201];
    printf("Enter a string(Max 200 characters): ");
    gets(str);
    printf("the reverse of %s is: ",str);
    reverseWords(str,strlen(str));
}