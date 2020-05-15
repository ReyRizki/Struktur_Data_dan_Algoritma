#include "student.h"

Student createStudent()
{
    Student student;
    student.hobbies = createList();
    return student;
}

StudentArr createStudentArr()
{
    StudentArr students;
    
    students.array = NULL;
    students.size = 0;

    return students;
}

void printStudent(Student student)
{
    printf("Name\t: %s\nNIS\t: %s\nHobbies\t: ", student.name, student.nis);
    printList(student.hobbies);
    printf("\n");
}

void printStudentArr(StudentArr studentArr)
{
    u int i;
    REP(i, 0, studentArr.size)
        printStudent(*(studentArr.array + i));
}

void addStudent(StudentArr *studentArr, char* name, char* nis)
{
    studentArr->array = (studentArr->array == NULL) ? (Student *) malloc(sizeof(Student)) : (Student *) realloc(studentArr->array, ((studentArr->size + 1) * sizeof(Student)));
    studentArr->size++;

    *(studentArr->array + studentArr->size - 1) = createStudent();
    strcpy((studentArr->array + studentArr->size - 1)->name, name);
    strcpy((studentArr->array + studentArr->size - 1)->nis, nis);
}

void insertStudentsHobby(Student *student, char* hobby)
{
    insertAtTail(&(student->hobbies), hobby);
}