#include "FIFO.h"

FIFO_status FIFO_init(FIFO_Buf** queue, unsigned int length){
    *queue = (FIFO_Buf *)malloc(sizeof(FIFO_Buf));
    if(!(*queue)){
        return FIFO_null; //dynamic allocation failed
    }
    (*queue)->length = length;
    (*queue)->base = (element_type *)malloc(length * sizeof(element_type));
    if(!((*queue)->base)){
        return FIFO_null; //dynamic allocation failed
    }
    (*queue)->head = (*queue)->base;
    (*queue)->tail = (*queue)->base;
    (*queue)->count = 0;

    return FIFO_no_error;
}


FIFO_status FIFO_is_full(FIFO_Buf* queue){
    if (!queue || !(queue->base) || !(queue->head)){
        return FIFO_null;
    }
    if(queue->count >= queue->length){ 
        return FIFO_full;
    }
    else{
        return FIFO_not_full;
    }
}

FIFO_status FIFO_is_empty(FIFO_Buf* queue){
    if (!queue || !(queue->base) || !(queue->head)){
        return FIFO_null;
    }
    if(queue->count == 0){
        return FIFO_empty;
    }
    else{
        return FIFO_not_empty;
    }
}

FIFO_status FIFO_front(FIFO_Buf* queue, element_type *item){
    if (!queue || !(queue->base) || !(queue->head)){
        return FIFO_null;
    }    
    if(queue->head == queue->base){
        return FIFO_empty;
    }
    *item = *(queue->tail);
    return FIFO_no_error;    
}

FIFO_status FIFO_enqueue(FIFO_Buf* queue, element_type item){
    if (!queue || !(queue->base) || !(queue->head)){
        return FIFO_null;
    }    
    if(FIFO_is_full(queue) == FIFO_full){
        return FIFO_full;
    }
    *(queue->head) = item;
    queue->head++;
   if(queue->head == queue->base + queue->length){
        queue->head = queue->base;
    }
    queue->count++;
    return FIFO_no_error;    
}

FIFO_status FIFO_dequeue(FIFO_Buf* queue, element_type *item){
    if (!queue || !(queue->base) || !(queue->head)){
        return FIFO_null;
    }    
    if(FIFO_is_empty(queue) == FIFO_empty){
        return FIFO_empty;
    }
    *item = *(queue->tail);
    queue->tail++;
    if(queue->tail == queue->base + queue->length){
        queue->tail = queue->base;
    }
    queue->count--;
    return FIFO_no_error;     
}

void FIFO_print_info(FIFO_Buf* queue){
    if (!queue || !(queue->base) || !(queue->head)){
        printf("Badly initialized FIFO\n\n");
        return;
    }        
    printf("===FIFO STATUS===\n");
    printf("Base is at %p\nHead is at %p\nTail is at %p\nNo. of elements is %d\n",
    queue->base,
    queue->head,
    queue->tail,
    queue->count);
    if (FIFO_is_empty(queue) == FIFO_empty){
        printf("empty FIFO\n\n");
        return;
    }     
    element_type* temp = queue->tail;
    printf("Items:\n");
    for(int i = 0 ; i < queue->count ; i++){
        printf("%d\n",*temp);
        if(temp == queue->base + queue->length){
            temp = queue->base;
        }
        else{
            temp++;
        }
    }
    printf("\n");
}