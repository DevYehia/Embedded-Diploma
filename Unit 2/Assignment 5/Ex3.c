#include <stdio.h>

typedef struct{
    float real;
    float imaginary;
} Complex;

//takes the Complex Number from user
void getComplexNum(Complex * num){
    printf("Enter real part: ");
    scanf("%f",&(num -> real));
    fflush(stdin);
    printf("Enter imaginary part: ");
    scanf("%f",&(num -> imaginary));
    fflush(stdin);
}

//gets Sum and prints it in format [Real]+[Complex]i"
void printComplexSum(Complex * num_one,Complex * num_two){

    printf("Sum = %.1f+%.1fi",
    num_one->real + num_two->real,
    num_one->imaginary + num_two->imaginary);

}

int main(){
    Complex num_one, num_two;
    printf("Enter 1st Complex Number \n");
    getComplexNum(&num_one);
    printf("\nEnter 2nd Complex Number\n");
    getComplexNum(&num_two);
    printf("\n");
    printComplexSum(&num_one,&num_two);
    
}