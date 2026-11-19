#include <stdio.h>

int is_leap_year(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main(void) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, weekday;
    printf("Enter year (1-9999): ");
    if (scanf("%d", &year) != 1 || year < 1 || year > 9999) { printf("Invalid year.\n"); return 1; }
    if (is_leap_year(year)) days[1] = 29;
    /* In the proleptic Gregorian calendar, 1 January 1 was a Monday. Sunday = 0. */
    int previous = year - 1;
    weekday = (1 + previous + previous / 4 - previous / 100 + previous / 400) % 7;
    for (int month = 0; month < 12; month++) {
        printf("\n     %s %d\n", months[month], year);
        printf("Su Mo Tu We Th Fr Sa\n");
        for (int i = 0; i < weekday; i++) printf("   ");
        for (int day = 1; day <= days[month]; day++) {
            printf("%2d ", day);
            weekday = (weekday + 1) % 7;
            if (weekday == 0) printf("\n");
        }
        if (weekday != 0) printf("\n");
    }
    return 0;
}
