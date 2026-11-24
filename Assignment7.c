#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

int main()
{
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the roll number, name and marks of 3 subjects for student %d:\n", i + 1);
        scanf("%d %s %d %d %d", &s[i].roll, s[i].name,
              &s[i].marks[0], &s[i].marks[1], &s[i].marks[2]);

        s[i].total = 0;
        for (j = 0; j < 3; j++)
            s[i].total += s[i].marks[j];

        s[i].percentage = s[i].total / 3.0;
    }

    printf("\n%-8s %-12s %-10s %-10s %-10s %-8s %-10s\n",
           "Roll No", "Name", "Subject:1", "Subject:2", "Subject:3", "Total", "Percentage");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-12s %-10d %-10d %-10d %-8d %-10.2f\n",
               s[i].roll, s[i].name,
               s[i].marks[0], s[i].marks[1], s[i].marks[2],
               s[i].total, s[i].percentage);
    }

    return 0;
}