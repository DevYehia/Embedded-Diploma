#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>
//Configurable data type
#define element_type unsigned char


//FIFO Data Type
typedef struct {
    unsigned int length;
    element_type* base;
    element_type* head;
    element_type* tail;
    unsigned int count;
} FIFO_Buf;

//Error States
typedef enum {
    FIFO_no_error,
    FIFO_full,
    FIFO_not_full,
    FIFO_empty,
    FIFO_not_empty,
    FIFO_null
} FIFO_status;
//Description: Create a struct instance of the FIFO
//Inputs: FIFO buffer and length
//Note: FIFO buffer has to be a pointer to pointer to struct
//output: initialized FIFO buffer and FIFO status (Null or No error)
FIFO_status FIFO_init(FIFO_Buf** queue, unsigned int length);
//Description: Push an Item onto the FIFO
//Inputs: FIFO buffer and added item
//output: FIFO status
FIFO_status FIFO_enqueue(FIFO_Buf* queue, element_type item);
//Description: pop an item from the FIFO
//Inputs: FIFO buffer
//outputs: FIFO status, popped item is pointed at by the pointer
FIFO_status FIFO_dequeue(FIFO_Buf* queue, element_type *item);
//Description: check if FIFO is full or not
//Inputs: FIFO buffer
//output: FIFO status (either FIFO_full  or FIFO_not_full)
FIFO_status FIFO_is_full(FIFO_Buf* queue);
//Description: check if FIFO is empty or not
//Inputs: FIFO buffer
//output: FIFO status (either FIFO_empty  or FIFO_not_empty)
FIFO_status FIFO_is_empty(FIFO_Buf* queue);
//Description: gets the item at the front of the queue without popping
//Inputs: FIFO buffer
//output: FIFO status,the value at the top of FIFO is pointed at by the pointer
FIFO_status FIFO_front(FIFO_Buf* queue, element_type *item);
//Description: prints base and head addresses. Also prints the count
//Inputs: FIFO buffer
//output: None
void FIFO_print_info(FIFO_Buf* queue);
#endif