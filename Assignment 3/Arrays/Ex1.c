#include <stdio.h>

int main(){
    float a[2][2];
    float b[2][2];
    printf("Enter the 1st matrix:\n");
    for(int i = 1 ; i <= 2 ; i++){
        for(int j = 1 ; j <= 2 ; j++){
            printf("Enter a%d%d: ",i,j);
            scanf("%f",&a[i-1][j-1]);
            fflush(stdin);
        }
    }
     printf("Enter the 2nd matrix:\n");
    for(int i = 1 ; i <= 2 ; i++){
        for(int j = 1 ; j <= 2 ; j++){
            printf("Enter b%d%d: ",i,j);
            scanf("%f",&b[i-1][j-1]);
            fflush(stdin);
        }
    }
    printf("\nThe Sum is:\n");
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            printf("%.1f\t",a[i][j] + b[i][j]);
        }
        printf("\n");
    }    
}