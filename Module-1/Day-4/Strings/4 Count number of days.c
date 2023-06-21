#include <stdio.h>

int isLeapYear(int year)
{
   if (year % 400 == 0)
      return 1;
   if (year % 100 == 0)
      return 0;
   if (year % 4 == 0)
      return 1;
   return 0;
}

int getDaysInMonth(int month, int year)
{
   int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (month == 2 && isLeapYear(year))
      return 29;
   return daysInMonth[month - 1];
}

int countDays(int day, int month, int year)
{
   int days = day;
   for (int i = 1; i < month; i++)
   {
      days += getDaysInMonth(i, year);
   }
   return days;
}

int main()
{
   int day, month, year;
   printf("Enter the date (DD/MM/YYYY): ");
   scanf("%d/%d/%d", &day, &month, &year);

   int days = countDays(day, month, year);

   printf("Number of days elapsed: %d\n", days);

   return 0;
}