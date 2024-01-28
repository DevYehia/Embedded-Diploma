#include <stdio.h>

int main(){
    int num;
    printf("Enter an integer: ");
    scanf("%d",&num);
    int sum = 0;
    for(int i = num ; i > 0 ; i--){
        sum += i;
    }
    printf("Sum is: %d",sum);
    //or we can just use the rule Sum = num(num+1)/2
}