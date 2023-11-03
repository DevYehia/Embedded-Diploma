#include <stdio.h>
#define MAX_ELEMENTS 100

int main(){
    float arr[MAX_ELEMENTS];
    int elementsNo;
    float sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d",&elementsNo);
    if(elementsNo > MAX_ELEMENTS){
        printf("Number of elements can\'t exceed %d",MAX_ELEMENTS);
        return 0;
    }
    for(int i = 0 ; i < elementsNo ; i++){
        printf("%d. Enter number: ",i+1);
        scanf("%f",&arr[i]);
        sum += arr[i];
        fflush(stdin);
    }
    printf("Average is %.2f",sum/elementsNo);
}