#include "LIFO.h"
#include <stdio.h>

int main(){
    element_type i, *temp;
    temp = (element_type *)malloc(sizeof(element_type));
    LIFO_Buf* first_buf;
    if(LIFO_init(&first_buf,5) == LIFO_no_error){
        printf("First Buffer allocated\n");
    }
    else{
        printf("Memory Allocation Failed");
        return 0;
    }
    LIFO_print_info(first_buf);
    printf("Now, push numbers from 1 to 5\n");
    for(i = 1 ; i <= 5 ; i++){
        LIFO_push(first_buf, i);
        printf("Push no. %d\n",i);
        LIFO_print_info(first_buf);
    }
    printf("Now, Let's attempt to push one more item\n");
    LIFO_push(first_buf,i);
    LIFO_print_info(first_buf);
    printf("Now, Let's pop these items\n");
    for(i = 1 ; i <= 5 ; i++){
        LIFO_pop(first_buf, temp);
        printf("Pop no. %d\n",i);
        printf("Popped item: %d\n",*temp);
        LIFO_print_info(first_buf);
    }
}