#include <stdio.h>

int isLeapYear(int year)
{

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0; 
}

int main()
{
    char dateStr[11];
    int day, month, year, i;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysElapsed = 0;

    printf("Enter the date in DD/MM/YYYY format: ");
    scanf("%10s", dateStr);

    sscanf(dateStr, "%d/%d/%d", &day, &month, &year);


    for (i = 1; i < month; i++)
    {
      
        if (i == 2 && isLeapYear(year))
            daysElapsed += 29; 
        else
            daysElapsed += daysInMonth[i]; 
    }

    daysElapsed += day;

    printf("Number of days elapsed: %d\n", daysElapsed);

    return 0;
}