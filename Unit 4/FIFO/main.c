#include "FIFO.h"
#include <stdio.h>

int main(){
    element_type i, *temp;
    temp = (element_type *)malloc(sizeof(element_type));
    FIFO_Buf* first_buf;
    if(FIFO_init(&first_buf,5) == FIFO_no_error){
        printf("First Buffer allocated\n");
    }
    else{
        printf("Memory Allocation Failed");
        return 0;
    }
    FIFO_print_info(first_buf);
    printf("Now, push numbers from 1 to 5\n");
    for(i = 1 ; i <= 5 ; i++){
        printf("Push no. %d\n",i);
        if(FIFO_enqueue(first_buf, i) == FIFO_full){
            printf("FIFO is Full\n");
        }
        FIFO_print_info(first_buf);
    }
    printf("Now, Let's attempt to push one more item\n");
    if(FIFO_enqueue(first_buf, i) == FIFO_full){
        printf("Can't Enqueue, FIFO is Full\n");
    }
    FIFO_print_info(first_buf);
    printf("Now, Let's pop these items\n");
    for(i = 1 ; i <= 5 ; i++){
        if(FIFO_dequeue(first_buf,temp) == FIFO_empty){
            printf("Can't Dequeue, Empty FIFO");
        }
        printf("Pop no. %d\n",i);
        printf("Popped item: %d\n",*temp);
        FIFO_print_info(first_buf);
    }
    printf("Let's try one more pop\n");
    if(FIFO_dequeue(first_buf,temp) == FIFO_empty){
        printf("Can't Dequeue, Empty FIFO\n");
    }
    FIFO_print_info(first_buf);
}