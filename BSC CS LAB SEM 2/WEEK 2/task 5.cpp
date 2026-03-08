#include <stdio.h>
#include <stdlib.h> 

struct Student {
    char name[50];
    int roll;
    int age;
    float marks;
};

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Roll number: ");
        scanf("%d", &students[i].roll);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n---- Student Information ----\n");
    for(i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name       : %s\n", students[i].name);
        printf("Roll No.   : %d\n", students[i].roll);
        printf("Age        : %d\n", students[i].age);
        printf("Marks      : %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}

