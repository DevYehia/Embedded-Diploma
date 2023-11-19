#include <stdio.h>

int factorial(int num){
    if(num == 0)
        return 1;
    return num * factorial(num - 1);
}



int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(num < 0){
        printf("Number has to be positive");
        return 0;
    }
    printf("The factorial of %d is %d",num,factorial(num));


}