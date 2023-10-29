#include <stdio.h>

int main(){
    int a,b;
    printf("Enter Value of a: ");
    fflush(stdout);
    scanf("%d",&a);
    fflush(stdin);
    printf("Enter Value of b: ");
    fflush(stdout);
    scanf("%d",&b);
    fflush(stdin);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("\nAfter swapping, value of a = %d\n",a);
    printf("\nAfter swapping, value of b = %d\n",b);
}