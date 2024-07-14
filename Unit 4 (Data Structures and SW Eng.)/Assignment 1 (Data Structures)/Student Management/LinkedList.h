#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int ID;
    char name[40];
    float height;
} SData;

typedef struct SStudentNode{
    SData student;
    struct SStudentNode* nextStudent;
} SStudentNode;


//Description: Fill data of node by taking user's input
//Inputs: Pointer to node to be filled
//output: None
void fill_the_record(SStudentNode* new_student);
//Description: Add item to Linked List
//Inputs: Address of pointer to Head of List
//output: None
void LIST_add_student(SStudentNode** head);
//Description: Delete item to Linked List by ID
//Inputs: Address of pointer to Head of List
//output: 0 ---> Fail, 1 ---> Success
char LIST_delete_student(SStudentNode** head);
//Description: View Info of all students
//Inputs: pointer to Head of List
//output: None
void LIST_view_students(SStudentNode* head);
//Description: Deletes all students
//Inputs: Address of pointer to Head of List
//output: None
void LIST_delete_all_students(SStudentNode** head);
//Description: Get Nth element like index an array for Nth item
//Inputs: Address of pointer to Head of List and index needed
//output: None
void LIST_get_Nth_student(SStudentNode* head, int n);
//Description: Get No. of elements in list iteratively
//Inputs: pointer to Head of List
//output: None
int LIST_get_count_iterative(SStudentNode* head);
//Description: Get No. of elements in list recursively
//Inputs: pointer to Head of List
//output: None
int LIST_get_count_recursive(SStudentNode* head);
//Description: Reverses the list
//Inputs: Address of pointer to Head of List
//output: None
void LIST_reverse(SStudentNode** head);

#endif