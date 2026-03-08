#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int age;
    float marks;
};

int main() {
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

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

    return 0;
}

