#include <stdio.h>
#include <stdlib.h>

int main()
{
    int birthDay, birthMonth, birthYear;
    int todayDay, todayMonth, todayYear;
    int dayDiff, monthDiff, yearDiff;

    printf("%s\n","Please enter birth day:");
    scanf("%d",&birthDay);
    printf("%s\n","Please enter birth month:");
    scanf("%d",&birthMonth);
    printf("%s\n","Please enter birth year:");
    scanf("%d",&birthYear);
    printf("%s\n","Please enter today's day:");
    scanf("%d",&todayDay);
    printf("%s\n","Please enter today's month:");
    scanf("%d",&todayMonth);
    printf("%s\n","Please enter today's year:");
    scanf("%d",&todayYear);

    dayDiff= todayDay-birthDay;
    monthDiff=todayMonth-birthMonth;
    yearDiff=todayYear-birthYear;

    if (monthDiff<0)
    {
        monthDiff+= 12;
        yearDiff-=1;
    }

    if (dayDiff<0)
    {
        dayDiff+=30;
        monthDiff-=1;
    }

   printf("Exact age is %d years, %d months and %d days.",yearDiff,monthDiff,dayDiff);





    return 0;
}
