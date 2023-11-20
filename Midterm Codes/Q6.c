#include <stdio.h>

int getUnique(int arr[],int size){
    int unique = arr[0];
    for(int i = 1 ; i < size ; i++){
        unique ^= arr[i];
    }
    return unique;
}


int main(){
    int arr[] = {4,2,5,2,5,7,4};
    printf("Result of Test Case 1 is: %d\n",getUnique(arr,sizeof(arr)/sizeof(arr[0])));
    int arr2[] = {4,2,4};
    printf("Result of Test Case 2 is: %d\n",getUnique(arr2,sizeof(arr2)/sizeof(arr2[0])));    
}