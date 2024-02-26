#ifndef LIFO_H
#define LIFO_H

#include <stdlib.h>
#include <stdio.h>
//Configurable data type
#define element_type unsigned char


//LIFO Data Type
typedef struct {
    unsigned int length;
    element_type* base;
    element_type* head;
    unsigned int count;
} LIFO_Buf;

//Error States
typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_not_full,
    LIFO_empty,
    LIFO_not_empty,
    LIFO_null
} LIFO_status;
//Description: Create a struct instance of the LIFO
//Inputs: LIFO buffer and length
//Note: LIFO buffer has to be a pointer to pointer to struct
//output: initialized LIFO buffer
LIFO_status LIFO_init(LIFO_Buf** stack, unsigned int length);
//Description: Push an Item onto the LIFO
//Inputs: LIFO buffer and added item
//output: LIFO status
LIFO_status LIFO_push(LIFO_Buf* stack, element_type item);
//Description: pop an item from the LIFO
//Inputs: LIFO buffer
//outputs: LIFO status, popped item is pointed at by the pointer
LIFO_status LIFO_pop(LIFO_Buf* stack, element_type *item);
//Description: check if LIFO is full or not
//Inputs: LIFO buffer
//output: LIFO status (either LIFO_full  or LIFO_not_full)
LIFO_status LIFO_is_full(LIFO_Buf* stack);
//Description: check if LIFO is empty or not
//Inputs: LIFO buffer
//output: LIFO status (either LIFO_empty  or LIFO_not_empty)
LIFO_status LIFO_is_empty(LIFO_Buf* stack);
//Description: gets the top item of LIFO without popping
//Inputs: LIFO buffer
//output: LIFO status,the value at the top of LIFO is pointed at by the pointer
LIFO_status LIFO_top(LIFO_Buf* stack, element_type *item);
//Description: prints base and head addresses. Also prints the count
//Inputs: LIFO buffer
//output: None
void LIFO_print_info(LIFO_Buf* stack);
#endif