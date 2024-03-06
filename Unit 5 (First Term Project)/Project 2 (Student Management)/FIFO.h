#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>
//Configurable data type
typedef struct {
    char firstName[40];
    char lastName[40];
    unsigned int rollNo;
    float GPA;
    unsigned int courses[10];
} element_type;


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
//Inputs: Address of pointer to FIFO buffer and length
//output: initialized FIFO buffer and FIFO status (Null or No error)
FIFO_status FIFO_init(FIFO_Buf** queue, unsigned int length);
//Description: Push an Item onto the FIFO
//Inputs: FIFO buffer and pointer to added item
//output: FIFO status (Null or Full or No Error)
FIFO_status FIFO_enqueue(FIFO_Buf* queue, element_type *item);
//Description: pop an item from the FIFO
//Inputs: FIFO buffer
//outputs: FIFO status (Null or Empty or No Error), popped item is pointed at by item
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
//output: FIFO status,the value at the top of FIFO is pointed at by item
FIFO_status FIFO_front(FIFO_Buf* queue, element_type *item);

#endif