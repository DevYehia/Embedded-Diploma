#include <stdio.h>

int main(){
    char operator;
    float a,b;
    printf("Enter an operator: ");
    scanf("%c",&operator);
    fflush(stdout),fflush(stdin);
    printf("Enter two operands: ");
    scanf("%f%f",&a,&b);
    float result;
    switch(operator){
        case '+':
        {
            result = a + b;
        }
        break;
        case '-':
        {
            result = a - b;
        }
        break;
        case '*':
        {
            result = a * b;
        }
        break;
        case '/':
        {
            if(b == 0){
                printf("Invalid Division");
                return 0;
            }
            result = a / b;
        }
        break;
        default:{
            printf("Invalid Operator");
            return 0;
        }
    }
    printf("%.2f %c %.2f = %.2f",a,operator,b,result);
}