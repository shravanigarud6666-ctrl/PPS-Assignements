#include <stdio.h>
#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[100];
    int marks[3];
    int total;
    double percentage;
};

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count;
    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_STUDENTS) {
        printf("Invalid number of students.\n"); return 1;
    }
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\nEnter roll number: ", i + 1);
        if (scanf("%d", &students[i].roll) != 1) return 1;
        printf("Enter name: ");
        if (scanf(" %99[^\n]", students[i].name) != 1) return 1;
        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for subject %d (0-100): ", j + 1);
            if (scanf("%d", &students[i].marks[j]) != 1 || students[i].marks[j] < 0 || students[i].marks[j] > 100) {
                printf("Invalid marks.\n"); return 1;
            }
            students[i].total += students[i].marks[j];
        }
        students[i].percentage = students[i].total / 3.0;
    }
    printf("\n%-10s %-20s %8s %8s %8s %8s %11s\n", "Roll No", "Name", "Sub 1", "Sub 2", "Sub 3", "Total", "Percentage");
    for (int i = 0; i < count; i++)
        printf("%-10d %-20s %8d %8d %8d %8d %10.2f%%\n", students[i].roll, students[i].name,
               students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].total, students[i].percentage);
    return 0;
}
