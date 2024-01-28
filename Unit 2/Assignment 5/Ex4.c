#include <stdio.h>
#define MAX_STUDENTS 10

typedef struct{
    char name[20];
    unsigned int roll;
    float marks;
} Student;


int main(){
    Student myStudents[MAX_STUDENTS];
    //Taking Input
    printf("Enter Information of Students:\n\n");
    for(int i = 0 ; i < MAX_STUDENTS ; i++){
        printf("For Roll Number: %d\n",i+1);
        myStudents[i].roll = i+1;
        printf("Enter Name: ");
        gets(myStudents[i].name);
        printf("Enter marks: ");
        scanf("%f",&myStudents[i].marks);
        while(getchar() != '\n');   //fflush(stdin) didn't work, this line is an alternative
        printf("\n");
    }
    //Displaying Structs
    printf("Displaying Information\n");
    for(int i = 0 ; i < MAX_STUDENTS ; i++){    
        printf("Information for Roll: %u\n",myStudents[i].roll);
        printf("name: %s\n",myStudents[i].name);
        printf("marks: %.1f\n\n",myStudents[i].marks);
    }
}