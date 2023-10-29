#include <stdio.h>

int main(){
    float a,b;
    printf("Enter Value of a: ");
    fflush(stdout);
    scanf("%f",&a);
    fflush(stdin);
    printf("Enter Value of b: ");
    fflush(stdout);
    scanf("%f",&b);
    fflush(stdin);
    float temp;
    temp = a;
    a = b;
    b = temp;
    printf("\nAfter swapping, value of a = %.2f\n",a);
    printf("\nAfter swapping, value of b = %.1f\n",b);
}