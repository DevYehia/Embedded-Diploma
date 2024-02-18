#include "LinkedList.h"

void fill_the_record(SStudentNode * new_student){
    char temp[40];
    printf("Enter the ID: ");
    gets(temp);
    new_student->student.ID = atoi(temp);
    printf("Enter the student's full name: ");
    gets(new_student->student.name);
    printf("Enter the height: ");
    gets(temp);
    new_student->student.height = atof(temp);    
}

void LIST_add_student(SStudentNode** head){
    SStudentNode* pLastStudent = *head;
    SStudentNode* pNewStudent;
    pNewStudent = (SStudentNode *)malloc(sizeof(SStudentNode));
    if((*head) == NULL){
        *head = pNewStudent;
    }
    else{
        while(pLastStudent->nextStudent != NULL){
            pLastStudent = pLastStudent->nextStudent;
        }
        pLastStudent->nextStudent = pNewStudent;
    }
    fill_the_record(pNewStudent);
    pNewStudent->nextStudent = NULL;
}

char LIST_delete_student(SStudentNode** head){
    char temp[10];
    SStudentNode* prev_student = NULL;
    SStudentNode* curr_student = *head;
    printf("Enter ID to be deleted: ");
    gets(temp);
    int selected_ID = atoi(temp);
    while(curr_student){
        if(curr_student->student.ID == selected_ID){
            if(prev_student){
                prev_student->nextStudent = curr_student->nextStudent;
            }
            else{
                *head = curr_student->nextStudent;
            }
            free(curr_student);
            return 1;
        }
        prev_student = curr_student;
        curr_student = curr_student->nextStudent;
    }
    printf("Can't find student ID\n");
    return 0;
}

void LIST_view_students(SStudentNode* head){
    SStudentNode* curr_student = head;
    int count = 1;
    if(!curr_student){
        printf("Empty List!!\n");
    }
    while(curr_student){
        printf("Record No %d\n",count);
        printf("ID: %d\n",curr_student->student.ID);
        printf("Name: %s\n",curr_student->student.name);
        printf("Height: %f\n",curr_student->student.height);
        curr_student = curr_student->nextStudent;
        count++;
    }
}

void LIST_delete_all_students(SStudentNode** head){
    SStudentNode* curr_student = *head;
    SStudentNode* prev_student = NULL;
    while(curr_student){
        prev_student = curr_student;
        curr_student = curr_student->nextStudent;
        free(prev_student);
    } 
    *head = NULL;
}

void LIST_get_Nth_student(SStudentNode* head, int n){
    int curr_index = 0;
    SStudentNode* curr_student = head;
    while(curr_index < n){
        if(!curr_student){
            printf("Index out of Bounds!!\n");
            return;
        }
        curr_student = curr_student-> nextStudent;
        curr_index++;
    }
    if(!curr_student){
        printf("Index out of Bounds!!\n");
        return;
    }
    printf("Student at Index %d\n",n);    
    printf("ID: %d\n",curr_student->student.ID);
    printf("Name: %s\n",curr_student->student.name);
    printf("Height: %f\n",curr_student->student.height);
}

int LIST_get_count_iterative(SStudentNode* head){
    int count = 0;
    SStudentNode* curr = head;
    while(curr){
        count++;
        curr = curr->nextStudent;
    }
    return count;
}

int LIST_get_count_recursive(SStudentNode* head){
    if(!head){
        return 0;
    }
    return 1 + LIST_get_count_recursive(head->nextStudent);
}

void LIST_reverse(SStudentNode** head){
    if(!head){
        return;
    }
    SStudentNode* prev = NULL;
    SStudentNode* curr = *head;
    SStudentNode* next = (*head) -> nextStudent;
    while(curr){
        curr->nextStudent = prev;
        prev = curr;
        curr = next;
        if(next){
            next = next->nextStudent;
        }
    }
    *head = prev;

}