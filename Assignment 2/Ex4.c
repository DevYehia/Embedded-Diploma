#include <stdio.h>

int main(){
    float num;
    printf("Enter an number: ");
    fflush(stdout);
    scanf("%f",&num);
    if(num > 0){
        printf("%.2f is positive",num);
    }
    else if(num < 0){
        printf("%.2f is negative",num);
    }
    else{
        printf("you entered zero",num);        
    }
}