#include <stdio.h>

int main(){
    int a[50][50]; 
    int rows,columns;
    printf("Enter No of rows: ");
    scanf("%d",&rows);
    fflush(stdin);
    printf("Enter No of columns: ");
    scanf("%d",&columns);
    fflush(stdin);    

    printf("Enter the matrix:\n");
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
            fflush(stdin);
        }
    }


    printf("\nThe Transpose is:\n");
    for(int i = 0 ; i < columns ; i++){
        for(int j = 0 ; j < rows ; j++){
            printf("%d\t",a[j][i]);
        }
        printf("\n");
    }    
}