#include <stdio.h>
#define MAX_ELEMENTS 100


int main(){
    int arr[MAX_ELEMENTS];
    int elementsNo,searchElement;
    printf("Enter the number of elements: ");
    scanf("%d",&elementsNo);
    if(elementsNo > MAX_ELEMENTS){
        printf("Number of elements can\'t exceed %d",MAX_ELEMENTS);
        return 0;
    }
    printf("Enter the array:\n");
    for(int i = 0 ; i < elementsNo ; i++){
        scanf("%d",&arr[i]);
        fflush(stdin);
    }
    printf("Enter the element to be searched for: ");
    scanf("%d",&searchElement);
    fflush(stdin);
    int i;
    for(i = 0 ; i < elementsNo ; i++){
        if(arr[i] == searchElement){
            printf("Element found at location: %d ",i+1);
            break;
        }   
    }
    if(i == elementsNo){
        printf("Element Not Found");
    }
}