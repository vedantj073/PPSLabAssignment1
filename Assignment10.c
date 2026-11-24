#include <stdio.h>

int isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Returns weekday of 1 January: 0 = Sunday, 1 = Monday, ..., 6 = Saturday */
int firstDayOfYear(int year)
{
    int y = year - 1;
    return (1 + 5 * (y % 4) + 4 * (y % 100) + 6 * (y % 400)) % 7;
}

int main()
{
    int year, month, day, startDay;
    const char *monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid year.\n");
        return 1;
    }

    if (isLeap(year))
        days[1] = 29;

    startDay = firstDayOfYear(year);

    printf("\n========== CALENDAR %d ==========\n", year);

    for (month = 0; month < 12; month++) {
        printf("\n   %s %d\n", monthNames[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (day = 0; day < startDay; day++)
            printf("    ");

        for (day = 1; day <= days[month]; day++) {
            printf("%3d ", day);
            if ((day + startDay) % 7 == 0)
                printf("\n");
        }
        printf("\n");

        startDay = (startDay + days[month]) % 7;
    }

    return 0;
}