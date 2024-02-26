#include "LinkedList.h"
#include <stdio.h>

SStudentNode* head = NULL;

int main(){
    char temp[40];
    printf("Welcome to your student management system\n");
    while(1){
        printf("\nChoose:\n");
        printf("1 ---> Add Student\n");
        printf("2 ---> Delete Student\n");
        printf("3 ---> View All Students\n");
        printf("4 ---> Delete All Students\n");
        printf("5 ---> Get Nth Student\n");
        printf("6 ---> Reverse the List\n");
        printf("Make your Choice: ");
        gets(temp);
        switch(atoi(temp)){
            case 1:
                LIST_add_student(&head);
                break;
            case 2:
                LIST_delete_student(&head);
                break;
            case 3:
                LIST_view_students(head);
                break;
            case 4:
                LIST_delete_all_students(&head);
                break;
            case 5:
                printf("Enter the index you want: ");
                gets(temp);
                LIST_get_Nth_student(head,atoi(temp));
                break;
            case 6:
                LIST_reverse(&head);
                break;
            default:
                printf("How could you pick a wrong option\n \
                Are you THAT stupid?!!\n");


        }
    } 
}