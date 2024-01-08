#include <stdio.h>
#define EMPLOYESS_NUM 2
typedef struct{
    char name[20];
    int ID;
} S_Employee;

int main(){
    S_Employee * employees[EMPLOYESS_NUM];
    S_Employee emp1 = {"Yehia",12};
    S_Employee emp2 = {"Sayed",14};
    employees[0] = &emp1;
    employees[1] = &emp2;
    S_Employee ** employeesPtr = employees;
    for(int i = 0 ; i < EMPLOYESS_NUM ; i++){
        printf("Employee %d:\n",i+1);
        printf("Employee name: %s\n",(*employeesPtr) -> name);
        printf("Employee ID: %d\n\n",(*employeesPtr) -> ID);
        employeesPtr++;
    } 

}