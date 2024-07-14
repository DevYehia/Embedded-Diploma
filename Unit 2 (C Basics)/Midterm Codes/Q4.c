#include <stdio.h>

unsigned int reverseNum(unsigned int num){
    unsigned int reversed = 0;
    while(num!=0){
        reversed*=10;
        reversed += (num%10);
        num/=10;
    }
    return reversed;
}


int main(){
    unsigned int n;
    printf("Please Enter a number: ");
    scanf("%u",&n);
    printf("the reverse of %u is: %u",n,reverseNum(n));

}