
#include <stdio.h>

struct student
{
    int roll;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

int main()
{
    struct student s[50];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if(n < 1 || n > 50)
    {
        printf("Invalid number of students");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        s[i].total = 0;

        printf("\nEnter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Enter marks of 3 subjects:\n");

        for(j = 0; j < 3; j++)
        {
            scanf("%d", &s[i].marks[j]);

            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3.0;
    }

    printf("\nRoll No\tName\tTotal\tPercentage\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%.2f\n",
        s[i].roll, s[i].name,
        s[i].total, s[i].percentage);
    }

    return 0;
}
