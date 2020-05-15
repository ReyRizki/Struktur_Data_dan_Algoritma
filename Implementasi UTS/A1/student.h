#ifndef STUDENT_H_
#define STUDENT_H_

#include "linkedList.h"

typedef struct
{
    char name[20], nis[10];
    List hobbies;
} Student;

typedef struct
{
    Student *array;
    u int size;
} StudentArr;

Student createStudent();
StudentArr createStudentArr();

void printStudent(Student student);
void printStudentArr(StudentArr studentArr);

void addStudent(StudentArr *studentArr, char* name, char* nis);
void insertStudentsHobby(Student *student, char* hobby);

#endif