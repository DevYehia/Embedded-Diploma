#include <stdio.h>

int countOnes(int num){
    int ones = 0;
    while(num != 0){
        ones += (num & 1);
        num >>= 1;
    }
    return ones;
}


int main(){
    int n;
    printf("Please Enter a number: ");
    scanf("%d",&n);
    printf("the number of binary ones in %d is %d",n,countOnes(n));    
}