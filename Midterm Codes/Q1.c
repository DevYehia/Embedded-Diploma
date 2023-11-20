#include <stdio.h>

unsigned int addDigits(unsigned int num){
    int sum = 0;
    while(num != 0){
        sum += (num%10);
        num/=10;
    }
    return sum;
}

int main(){
    unsigned int n;
    printf("Please Enter a number: ");
    scanf("%u",&n);
    printf("the sum of its digits is: %u",addDigits(n));

}