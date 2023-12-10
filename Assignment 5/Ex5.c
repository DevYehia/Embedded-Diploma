#include <stdio.h>
#define PI 3.14
#define CircleArea(radius) (PI*radius*radius)

int main(){
    unsigned int radius;
    printf("Enter the radius: ");
    scanf("%u",&radius);
    printf("Area of Circle = %.2f",CircleArea(radius));
}