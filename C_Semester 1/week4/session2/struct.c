 #include <stdio.h>
 #include <string.h>

 struct student {
 char name [20];
 char student_id [11];
 unsigned mark;
 };

 int main () {
    struct student new_student;
    printf("Enter the student name,id and mark\n");
    scanf("%s %s %u", new_student.name, new_student.student_id, &new_student.mark);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Final mark: %u\n", new_student.mark);

    return 0;
    }
