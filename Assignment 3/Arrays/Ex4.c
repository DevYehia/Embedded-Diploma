#include <stdio.h>
#define MAX_ELEMENTS 100


int main(){
    int arr[MAX_ELEMENTS];
    int elementsNo,newElement,insertIndex;
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
    printf("Enter the element to be inserted: ");
    scanf("%d",&newElement);
    fflush(stdin);
    printf("Enter its location: ");
    scanf("%d",&insertIndex);
    insertIndex--;
    if(insertIndex < 0 || insertIndex > elementsNo + 1){
        printf("Invalid Index");
        return 0;
    }
    for(int i = elementsNo ; i > insertIndex ; i--){
        arr[i] = arr[i-1];
    }
    arr[insertIndex] = newElement;
    elementsNo++;
    printf("Now the array is:\n");
    for(int i = 0 ; i < elementsNo ; i++){
        printf("%d ",arr[i]);
    }
}