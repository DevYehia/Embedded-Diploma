#include "Student.h"

static FIFO_Buf* students;

static void student_init(void){
    if (FIFO_init(&students, MAX_STUDENTS) == FIFO_null){
        printfRed("Failed to Initialize FIFO, Not Enough Memory!!\n");
        return;
    }
    printfGreen("Initialized FIFO Sucessfully\n");
}

void start_system(void){
    student_init();
    int choice;
    while(1){
        printfBlue("\n----STUDENT MANAGER----\n");
        printfMagenta("1- Add Students from File\n");
        printfMagenta("2- Add Student Manually\n");
        printfMagenta("3- Find Student by roll number\n");
        printfMagenta("4- Find Students by First Name\n");
        printfMagenta("5- Find Students in a course\n");
        printfMagenta("6- Update Student\n");
        printfMagenta("7- Delete Student\n");
        printfMagenta("8- Show All Students\n");
        printfMagenta("9- Get Number of Students\n");
        printfMagenta("10- Exit\n");        
        printf("\nYour Choice: ");
        myScanf(" %d",&choice);
        switch(choice){
        case 1:
        {
            student_add_file();
        }
        break;
        case 2:
        {
            student_add_manual();
        }
        break;
        case 3:
        {
            unsigned int roll;
            printfYellow("Enter the roll number: ");
            myScanf(" %u",&roll);
            element_type* student = find_student_by_roll(roll);
            if(!student){
                printfRed("Student Not Found!!\n");
            }
            else{
                printfGreen("Found Successfully!\n");
                printStudent(student);
            }
        }
        break;
        case 4:
        {
            char fName[40];
            printfYellow("Enter the first name: ");
            safeInput(fName, 40);
            find_students_by_fname(fName);
        }
        break;
        case 5:
        {
            unsigned int cID;
            printfYellow("Enter the course number: ");
            myScanf(" %u",&cID);
            find_students_in_course(cID);
        }
        break;
        case 6:
        {
            update_student();
        }
        break;
        case 7:
        {
            delete_student();
        }
        break;
        case 8:{
            print_all_students();
        }
        break;
        case 9:
        {
            get_students_num();
        }
        break;
        case 10:
        {
            return;
        }
        break;
        default:
        {
            printfRed("Wrong Option\n");
        }
        }
    }
}

void student_add_manual(void){
    FIFO_status FIFO_state = FIFO_is_full(students);
    if(FIFO_state == FIFO_full){
        printfRed("Database is Full!!\n");
        return;
    }
    else if(FIFO_state == FIFO_null){
        printfRed("Uninitialized DataBase!!\n");
        return;
    }
    element_type newStudent;
    for(int i = 0 ; i < 10 ; i++){
        newStudent.courses[i] = 0;
    }
    while(1){
        printfCyan("Enter the Roll Number: ");
        myScanf(" %d", &(newStudent.rollNo));
        if(find_student_by_roll(newStudent.rollNo)){
            printfRed("Roll Number Already Exists!!\nEnter Another One\n");
            continue;
        }
        break;
    }
    printfCyan("Enter the first Name: ");
    safeInput(newStudent.firstName,40);
    printfCyan("Enter the last Name: ");
    safeInput(newStudent.lastName,40);
    while(1){
        printfCyan("Enter the GPA : ");
        myScanf(" %f", &(newStudent.GPA));
        if(newStudent.GPA < 0 || newStudent.GPA > 4){
            printfRed("Invalid GPA, Try Again\n");
            continue;
        }
        break;
    }
    unsigned int numCourses;
    while(1){
        printfCyan("Enter the number of courses (MAX 10): ");
        myScanf(" %u", &numCourses);
        if(numCourses > 10){
            printfRed("MAX is 10 courses, try again\n");
            continue;
        }
        break;
    }

    for(int i = 0 ; i < numCourses ; i++){
        while(1){
            char enrolled = 0;
            printfCyan("Enter the ID of course No. %d: ",i+1);
            myScanf(" %u",&(newStudent.courses[i]));
            if(newStudent.courses[i] == 0){
                printfRed("ID can't be 0\n");
                continue;
            }
            for(int j = 0 ; j < i ; j++){
                if(newStudent.courses[j] == newStudent.courses[i]){
                    printfRed("Course Already Enrolled!!\n");
                    enrolled = 1;
                    break;
                }
            }
            if(enrolled){
                continue;
            }
            break;
        }
    }
    FIFO_enqueue(students,&newStudent);
    printfGreen("Student Added Successfully!\n");

}

void student_add_file(void){
    FIFO_status FIFO_state = FIFO_is_full(students);
    if(FIFO_state == FIFO_full){
        printfRed("Database is Full!!\n");
        return;
    }
    else if(FIFO_state == FIFO_null){
        printfRed("Uninitialized DataBase!!\n");
        return;
    }
    int counter = 1;
    element_type* newStudent;
    FILE* fp;
    char line[200];
    fp = fopen("student.txt","r");
    while(fgets(line,200,fp)){ 
        printfCyan("\nReading Student Number %d\n",counter);
        counter++;
        char* token = strtok(line," ");
        newStudent = (element_type *)malloc(sizeof(element_type));
        for(int i = 0 ; i < 10 ; i++){
            newStudent->courses[i] = 0;
        }
        newStudent->rollNo = atoi(token);
        if(find_student_by_roll(newStudent->rollNo)){
            printfRed("Roll Number Already Exists!!,Student not Registered\n");
            free(newStudent);
            continue;
        }
        token = strtok(NULL," ");
        if(token == NULL){
            printfRed("Discarding Incomplete Student Data!\n");
            free(newStudent);
            return;
        }
        strcpy(newStudent->firstName,token);
        token = strtok(NULL," ");
        if(token == NULL){
            printfRed("Discarding Incomplete Student Data!\n");
            free(newStudent);
            return;
        }
        strcpy(newStudent->lastName,token);
        token = strtok(NULL," ");
        if(token == NULL){
            printfRed("Discarding Incomplete Student Data!\n");
            free(newStudent);
            return;
        }
        
        newStudent->GPA = atof(token);
        if(newStudent->GPA < 0 || newStudent->GPA > 4){
            printfRed("Invalid GPA, Defaulting to 2\n");
            newStudent->GPA = 2;
        }
        token = strtok(NULL," ");
        for(int i = 0 ; token != NULL && i < 10 ; i++, token = strtok(NULL," ")){
            char enrolled = 0;
            newStudent->courses[i] = atoi(token);
            if(newStudent->courses[i] == 0){
                printfRed("Discarding Invalid Course ID = 0\n");
                continue;
            }
            for(int j = 0 ; j < i ; j++){
                if(newStudent->courses[j] == newStudent->courses[i]){
                    printfRed("Discarding Duplicate Course!!\n");
                    enrolled = 1;
                    break;
                }
            }
            if(enrolled){
                newStudent->courses[i] = 0;
                continue;
            }
            }
        FIFO_enqueue(students,newStudent);
        printfGreen("Student Added Successfully!\n");    
        printStudent(newStudent);
        free(newStudent);
    }
}

element_type* find_student_by_roll(int rollNo){
    element_type* temp = students->tail;
    while(temp != students->head){
        if(temp -> rollNo == rollNo){
            return temp;
        }
        if(temp == students->base + students->length - 1){
            temp = students->base;
        }
        else{
            temp++;
        }
    }
    return (void *) 0;
}

void find_students_by_fname(char* fName){
    printfBlue("The Students with first name %s are:\n",fName);
    element_type* temp = students->tail;
    char found = 0;
    while(temp != students->head){
        if(strcmp(temp->firstName, fName) == 0){
            printStudent(temp);
            found = 1;
        }
        if(temp == students->base + students->length - 1){
            temp = students->base;
        }
        else{
            temp++;
        }
    }
    if(!found){
        printfRed("No Student has this name\n");
    }
}

void find_students_in_course(unsigned int cID){
    printfBlue("The Students enrolled in course %d are:\n",cID);
    element_type* temp = students->tail;
    char found = 0;
    while(temp != students->head){
        for(int j = 0 ; j < 10 ; j++){
            if(temp->courses[j] == 0){
                break;
            }
            if(temp->courses[j] == cID){
                printStudent(temp);
                found = 1;
                break;
            }
        }
        if(temp == students->base + students->length - 1){
            temp = students->base;
        }
        else{
            temp++;
        }
    }
    if(!found){
        printfRed("No Student has enrolled in this Course\nor This Course doesn't exist\n");
    }
}

void get_students_num(void){
    printfBlue("Number of students in system is %d student",students->count);
    if(students->count != 1){
        printfBlue("s");
    }
    printf("\n");
    printfBlue("There are %d available slots in the Queue\n",students->length - students->count);
}

void update_student(void){
    unsigned int rollNo;
    printfYellow("Please Enter the roll number: ");
    myScanf(" %u",&rollNo);
    element_type* student = find_student_by_roll(rollNo);
    if(!student){
        printfRed("No student has this roll number!\n");
        return;
    }

    char choice;
    printfCyan("Current Roll Number: %d\n",student->rollNo);
    printfYellow("Do you want to update the roll number(y/n): ");
    myScanf(" %c",&choice);
    if(choice == 'y'){
        modifyRoll(student);
    }

    printfCyan("Current First Name: %s\n",student->firstName);
    printfYellow("Do you want to update the first name(y/n): ");
    myScanf(" %c",&choice);
    if(choice == 'y'){
        modifyFirstName(student);
    }

    printfCyan("Current Last Name: %s\n",student->lastName);
    printfYellow("Do you want to update the last name(y/n): ");
    myScanf(" %c",&choice);
    if(choice == 'y'){
        modifyLastName(student);
    }
    printfCyan("Current GPA: %f\n",student->GPA);
    printfYellow("Do you want to update the student's GPA(y/n): ");
    myScanf(" %c",&choice);
    if(choice == 'y'){
        modifyGPA(student);
    }

    printfCyan("Current Courses: \n");
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == 0){
            break;
        }
        printfCyan("%d ",student->courses[i]);
    }

    printfYellow("\nDo you want to update the student's courses(y/n): ");
    myScanf(" %c",&choice);
    if(choice == 'y'){
        modifyCourses(student);
    }
    printfGreen("Successfully modified student!\n");
    printStudent(student);

}

void delete_student(void){
    unsigned int rollNo;
    printfYellow("Please Enter the roll number: ");
    myScanf(" %u",&rollNo);
    if(!find_student_by_roll(rollNo)){
        printfRed("No student has this roll number!\n");
        return;
    }
    element_type student;
    //keep on dequeuing and enqueuing till finding student then don't enqueue
    while(1){
        FIFO_dequeue(students, &student);
        if(student.rollNo == rollNo){
            break;
        }
        FIFO_enqueue(students, &student);
    }
    printfGreen("Student Successfully removed!\n");
}


static void modifyRoll(element_type* student){
    while(1){
        unsigned int newRollNo;
        printfYellow("Enter the new roll number: ");
        myScanf(" %u",&newRollNo);
        element_type* otherStudent = find_student_by_roll(newRollNo);
        if(otherStudent && otherStudent != student){
            printfRed("A student already has this roll number!\n");
            continue;
        }
        student->rollNo = newRollNo;
        break;
    }
}

static void modifyFirstName(element_type* student){
    char newfName[40];
    printfYellow("Enter the first name: ");
    safeInput(newfName, 40);
    strcpy(student->firstName, newfName);
}

static void modifyLastName(element_type* student){
    char newLastName[40];
    printfYellow("Enter the last name: ");
    safeInput(newLastName, 40);
    strcpy(student->lastName, newLastName);
}

static void modifyGPA(element_type* student){
    float newGPA;
    while(1){
        printfYellow("Enter the new GPA: ");
        myScanf(" %f", &newGPA);
        if(newGPA < 0 || newGPA > 4){
            printfRed("Invalid GPA try Again\n");
            continue;
        }
        break;
    }
    student->GPA = newGPA;
}

static void modifyCourses(element_type* student){
    char choice;
    while(1){
        printfYellow("\n1- Add Course\n2- Change Course\n3- Remove Course\n4- Exit Course Modification\n");
        printfYellow("Your Choice: ");
        myScanf(" %d",&choice);
        switch(choice){
            case 1:
            {
                addCourse(student);
            }
            break;
            case 2:
            {
                changeCourse(student);
            }
            break;
            case 3:
            {
                removeCourse(student);
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
                printfRed("Invalid Choice!\n");
            }
        }
        printfCyan("Courses Now: ");
        for(int i = 0 ; i < 10 ; i++){
            if(student->courses[i] == 0){
                continue;
            }
            printfCyan("%d ",student->courses[i]);
        }
        printf("\n");
    }
}
static void addCourse(element_type* student){
    int numCourses = 0;
    char found = 0;
    unsigned int cID;
    int emptySlot;
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] != 0){
            numCourses++;
        }
    }
    if(numCourses == 10){
        printfRed("No more than 10 courses is allowed!\n");
        return;
    }
    printfYellow("Which Course is to be added: ");
    myScanf(" %u",&cID);
    if(cID == 0){
        printfRed("Invalid Course ID!\n");
        return;
    }
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == cID){
            found = 1;
            break;
        }
    }
    if(found){
        printfRed("Course is already enrolled!\n");
        return;
    }
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == 0){
            emptySlot = i;
            break;
        }
    }
    student->courses[emptySlot] = cID;
    printfGreen("Successfully Added!\n");
}


static void removeCourse(element_type* student){
    unsigned int cID;
    char found = 0;
    printfYellow("Which Course will be removed: ");
    myScanf(" %u",&cID);
    if(cID == 0){
        printfRed("Invalid Course ID!\n");
        return;
    }
    for(int i = 0 ; i < 10 ; i++){
        if(cID == student->courses[i]){
            student->courses[i] = 0;
            found = 1;
            break;
        }
    }
    if(!found){
        printfRed("Student is not enrolled in this course!\n");
    }
    else{
        printfGreen("Successfully Removed!\n");
    }
}

static void changeCourse(element_type* student){
    unsigned int cID;
    int oldCourseIndex = -1;
    char enrolled = 0;
    printfYellow("Enter the course you would like to change: ");
    myScanf(" %u",&cID);
    if(cID == 0){
        printfRed("Invalid Course ID!\n");
        return;
    }
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == cID){
            oldCourseIndex = i;
            break;
        }
    }
    if(oldCourseIndex == -1){
        printfRed("Student is not enrolled in this course!\n");
        return;
    }
    printfYellow("Enter the new course: ");
    myScanf(" %u",&cID);
    if(cID == 0){
        printfRed("Invalid Course ID!\n");
        return;
    }

    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == cID){
            enrolled = 1;
            break;
        }
    }
    if(enrolled){
        printfRed("Student is already enrolled in this course!\n");
        return;
    }
    student->courses[oldCourseIndex] = cID;
    printfGreen("Successfully Modified Course!\n");
}


void printStudent(element_type* student){
    printfBlue("-----------------\n");
    printfMagenta("Roll No.: %u\n",student->rollNo);
    printfMagenta("Name: %s %s\n",student->firstName,student->lastName);
    printfMagenta("GPA: %.2f\n",student->GPA);
    printfMagenta("Courses Enrolled: ");
    for(int i = 0 ; i < 10 ; i++){
        if(student->courses[i] == 0){
            continue;
        }
        printfMagenta("%d ",student->courses[i]);
    }
    printfBlue("\n-----------------\n");
}

void print_all_students(void){
    element_type* student = students->tail;
    while(student != students->head){
        printStudent(student);
        if(student == students->base + students->length){
            student = students->base;
        }
        else{
            student++;
        }        
    }
}
