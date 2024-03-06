#ifndef STUDENT_H
#define STUDENT_H

#include "FIFO.h"
#include "util.h"
#include <string.h>
#include <stdio.h>

#define MAX_STUDENTS 50


//prototypes


//Description: Add student manually to Queue
void student_add_manual(void);

//Description: Add student Reading from File
void student_add_file(void);

//Description: Find Student by Roll No.
//Inputs: Roll No
//Outputs: Address of student found or NULL
element_type* find_student_by_roll(int rollNo);

//Description: Find all students with the input first name
//Inputs: First Name to be searched for
void find_students_by_fname(char* fName);

//Description: Prints details of all students enrolled in course with ID = cID
void find_students_in_course(unsigned int cID);

//Description: get number of students in system
void get_students_num(void);

//Description: update student identified by roll number
void update_student(void);

//Description: delete student identified by roll number
void delete_student(void);

//Description: Prompt User for student management options
void start_system(void);

//Description: Prints All the data about all the students in the system
void print_all_students(void);

void printStudent(element_type* student);


//helper functions that shouldn't be exposed to user

static void modifyRoll(element_type* student);

static void modifyFirstName(element_type* student);

static void modifyLastName(element_type* student);

static void modifyGPA(element_type* student);

static void modifyCourses(element_type* student);

static void addCourse(element_type* student);

static void removeCourse(element_type* student);

static void changeCourse(element_type* student);

//Description: Initialize the FIFO for storing students
static void student_init(void);

#endif