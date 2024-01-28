#include <stdio.h>

int main(){
    float a,b,c,largest;
    printf("Enter three numbers: ");
    fflush(stdout);
    scanf("%f%f%f",&a,&b,&c);
    if(a > b){
        if(a > c)
            largest = a;
        else
            largest = c;
    }
    else{
        if(b > c)
            largest = b;
        else
            largest = c;
    }
    printf("Largest number is: %.2f",largest);
}