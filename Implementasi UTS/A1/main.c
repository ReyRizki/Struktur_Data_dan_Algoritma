#include "student.h"

int main()
{
    StudentArr studentArr = createStudentArr();
    addStudent(&studentArr, "Reina", "161710065");
    insertStudentsHobby((studentArr.array + 0), "Makan");
    insertStudentsHobby((studentArr.array + 0), "Tidur");
    insertStudentsHobby((studentArr.array + 0), "Bangun");

    addStudent(&studentArr, "Rey", "191524031");
    insertStudentsHobby((studentArr.array + 1), "Nonton");
    insertStudentsHobby((studentArr.array + 1), "Baca");

    addStudent(&studentArr, "Rielandy", "46");

    addStudent(&studentArr, "Riela", "007");
    insertStudentsHobby((studentArr.array + 3), "Parkour");
    
    printStudentArr(studentArr);
}