#include <stdio.h>

int main(){
    int num;
    printf("Please Enter an integer: ");
    scanf("%d",&num);
    if(num < 0){
        printf("Error! Number can\'t be negative");
        return 0;
    }
    int fact = 1;
    for(int i = 2 ; i <= num ; i++){
        fact *= i;
    }
    printf("Factorial of %d is %d",num,fact);
}