#include <stdio.h>
#include <math.h>

float mySqrt(unsigned int num){
    return sqrt(num);
}


int main(){
    unsigned int n;
    printf("Please Enter a number: ");
    scanf("%u",&n);
    printf("the square root of %u is: %.3f",n,mySqrt(n));

}