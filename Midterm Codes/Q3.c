#include <stdio.h>

//returns 1 if number if prime otherwise 0
char isNumPrime(int num){
    if(num <= 1)
        return 0;
    for(int i = 2 ; i * i <= num ; i++){//keep going till i <= sqrt(num)
        if(num % i == 0)
            return 0;
    }
    return 1;
}

//prints all prime numbers from start to end (inclusive)
void getPrimeBetween(int start, int end){
    for(int i = start ; i <= end ; i++){
        if(isNumPrime(i))
            printf("%d ",i);
    }
}

int main(){
    int start,end;
    printf("Please Enter your start and end numbers: ");
    scanf("%d%d",&start,&end);
    getPrimeBetween(start,end);
}