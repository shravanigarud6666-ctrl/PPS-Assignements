
#include <stdio.h>
#include <time.h>

int main()
{
    int year, month, day;
    int days[] = {31,28,31,30,31,30,
                  31,31,30,31,30,31};

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    struct tm date;
    
    printf("Enter year: ");
    scanf("%d", &year);

    if(year < 1 || year > 9999)
    {
        printf("Invalid year");
        return 0;
    }

    if((year % 400 == 0) ||
       (year % 4 == 0 && year % 100 != 0))
    {
        days[1] = 29;
    }

    for(month = 0; month < 12; month++)
    {
        date = (struct tm){0};

        date.tm_year = year - 1900;
        date.tm_mon = month;
        date.tm_mday = 1;

        mktime(&date);

        printf("\n\n      %s %d\n", months[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for(day = 0; day < date.tm_wday; day++)
        {
            printf("    ");
        }

        for(day = 1; day <= days[month]; day++)
        {
            printf("%3d ", day);

            if((day + date.tm_wday) % 7 == 0)
            {
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}
