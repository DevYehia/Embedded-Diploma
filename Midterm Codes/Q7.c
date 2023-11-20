#include <stdio.h>

//Note: I solved this problem using two different ways

int add(int start,int end){
    if(start == end){
        return start;
    }
    return start + add(start+1,end);
}

int add2(int num){
    return num*(num+1)/2; 
}

int main(){
    printf("Solution using recursion (1st Method): %d\n",add(1,100));
    printf("Solution using formula (2nd Method): %d",add2(100));
}