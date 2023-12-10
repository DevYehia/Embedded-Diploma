#include <stdio.h>

typedef struct{
    unsigned int feet;
    float inches;
} Distance;

//takes the distance as input from the user
void getDistance(Distance * d){
    printf("Enter feet: ");
    scanf("%u",&(d -> feet));
    fflush(stdin);
    printf("Enter inch: ");
    scanf("%f",&(d -> inches));
    fflush(stdin);
}

//gets Sum and prints it in format [Feets]'-[Inches]"
void printDistanceSum(Distance * d_one,Distance * d_two){
    unsigned int feet_sum = d_one -> feet + d_two -> feet;
    float inch_sum = d_one -> inches + d_two -> inches;
    feet_sum += (int)inch_sum / 12;
    while(inch_sum > 12){
        inch_sum -= 12;
    }
    printf("Sum of Distances = %u\'-%.1f\"",feet_sum,inch_sum);
}

int main(){
    Distance d_one, d_two;
    printf("Enter info for 1st distance\n");
    getDistance(&d_one);
    printf("\nEnter info for 2nd distance\n");
    getDistance(&d_two);
    printf("\n");
    printDistanceSum(&d_one,&d_two);
    
}