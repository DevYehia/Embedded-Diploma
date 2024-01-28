#include <stdio.h>

int main(){
int arr[15];
printf("Input the number of elements to store in the array (max 15) : ");
char numOfElements;
scanf("%d",&numOfElements);
fflush(stdin);
printf("Input %d number of elements in the array :\n",numOfElements);
for(char i = 0 ; i < numOfElements ; i++){
    printf("element - %d : ",i+1);
    scanf("%d",&arr[i]);
    fflush(stdin);
}
int* ptr = &arr[numOfElements - 1];
printf("Array in reverse order:\n");
for(char i = numOfElements - 1 ; i >= 0 ;i--){
    printf("element - %d : %d\n",i+1,*ptr);
    ptr--;
}
}