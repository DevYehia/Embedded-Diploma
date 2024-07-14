#include <stdio.h>

void reverseArray(int arr[],int size){
    int tmp;
    for(int i = 0, j = size - 1 ; i < size/2 ; i++ , j--){
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("The array is: ");
    for(int i = 0 ; i < arrSize ; i++){
        printf("%d ",arr[i]);
    }
    reverseArray(arr,arrSize);
    printf("\nThe reverse of the array is: ");
    for(int i = 0 ; i < arrSize ; i++){
        printf("%d ",arr[i]);
    }
}