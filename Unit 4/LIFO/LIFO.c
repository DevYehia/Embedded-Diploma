#include "LIFO.h"

LIFO_status LIFO_init(LIFO_Buf** stack, unsigned int length){
    *stack = (LIFO_Buf *)malloc(sizeof(LIFO_Buf));
    if(!(*stack)){
        return LIFO_null; //dynamic allocation failed
    }
    (*stack)->length = length;
    (*stack)->base = (element_type *)malloc(length * sizeof(element_type));
    if(!((*stack)->base)){
        return LIFO_null; //dynamic allocation failed
    }
    (*stack)->head = (*stack)->base;
    (*stack)->count = 0;

    return LIFO_no_error;
}


LIFO_status LIFO_is_full(LIFO_Buf* stack){
    if (!stack || !(stack->base) || !(stack->head)){
        return LIFO_null;
    }
    if(stack->head >= stack->base + stack->length){
        return LIFO_full;
    }
    else{
        return LIFO_not_full;
    }
}

LIFO_status LIFO_is_empty(LIFO_Buf* stack){
    if (!stack || !(stack->base) || !(stack->head)){
        return LIFO_null;
    }
    if(stack->head == stack->base){
        return LIFO_empty;
    }
    else{
        return LIFO_not_empty;
    }
}

LIFO_status LIFO_top(LIFO_Buf* stack, element_type *item){
    if (!stack || !(stack->base) || !(stack->head)){
        return LIFO_null;
    }    
    if(stack->head == stack->base){
        return LIFO_empty;
    }
    *item = *(stack->head) - 1;    
    return LIFO_no_error;
}

LIFO_status LIFO_push(LIFO_Buf* stack, element_type item){
    if (!stack || !(stack->base) || !(stack->head)){
        return LIFO_null;
    }    
    if(LIFO_is_full(stack) == LIFO_full){
        return LIFO_full;
    }
    *(stack->head) = item;
    stack->head++;
    stack->count++;
    return LIFO_no_error;    
}

LIFO_status LIFO_pop(LIFO_Buf* stack, element_type *item){
    if (!stack || !(stack->base) || !(stack->head)){
        return LIFO_null;
    }    
    if(LIFO_is_empty(stack) == LIFO_empty){
        return LIFO_empty;
    }
    stack->head--;
    *item = *(stack->head);
    stack->count--;
    return LIFO_no_error;    
}

void LIFO_print_info(LIFO_Buf* stack){
    if (!stack || !(stack->base) || !(stack->head)){
        printf("Badly initialized LIFO\n\n");
        return;
    }        
    printf("===LIFO STATUS===\n");
    printf("Base is at %p\nHead is at %p\nNo. of elements is %d\n",
    stack->base,
    stack->head,
    stack->count);
    if (LIFO_is_empty(stack) == LIFO_empty){
        printf("empty LIFO\n\n");
        return;
    }     
    element_type* temp = stack->head - 1;
    printf("Items:\n");
    while(temp >= stack->base){
        printf("%d\n",*temp);
        temp--;
    }
    printf("\n");
}