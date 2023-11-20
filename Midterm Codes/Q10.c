#include <stdio.h>

int countMaxOnesBetZeroes(int num){
    while(num & 1){ //execute till find first zero from the right
        num >>= 1;
    }
    int max = 0, count = 0;
    while(num != 0){
        
        if((num & 1) == 0){
            if(count > max){
                max = count;
            }
        count = 0;
        }
        else{
            count++;
        }
        num >>= 1;
    }
    return (count > max) ? count : max;

}


int main(){
    int n;
    printf("Please Enter a number: ");
    scanf("%d",&n);
    printf("the max number of ones between two zeroes in %d is %d",n,countMaxOnesBetZeroes(n));    
}