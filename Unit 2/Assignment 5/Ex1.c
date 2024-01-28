#include <stdio.h>

typedef struct{
    char name[20];
    unsigned int roll;
    float marks;
} Student;


int main(){
    Student myStudent;
    //Taking Input
    printf("Enter Information of Students:\n\n");
    printf("Enter Name: ");
    gets(myStudent.name);
    printf("Enter Roll Number: ");
    scanf("%d",&myStudent.roll);
    fflush(stdin);
    printf("Enter marks: ");
    scanf("%f",&myStudent.marks);
    printf("\n");
    //Displaying Struct
    printf("Displaying Information\n");
    printf("name: %s\n",myStudent.name);
    printf("Roll: %u\n",myStudent.roll);
    printf("marks: %.1f\n",myStudent.marks);
}