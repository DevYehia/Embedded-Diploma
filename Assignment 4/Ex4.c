#include <stdio.h>

int myPow(int base,int power){
    if(power == 0)
        return 1;
    return base * myPow(base,power - 1);
}



int main(){
    int base,power;
    printf("Enter the base: ");
    scanf("%d",&base);
    fflush(stdin);
    printf("Enter the power(+ve only): ");
    scanf("%d",&power);
    printf("%d^%d is %d",base,power,myPow(base,power));
}