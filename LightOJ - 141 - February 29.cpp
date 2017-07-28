#include<bits/stdc++.h>

using namespace std;

bool isleap(long long int year)
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0)) return true;
    return false;
}

int main()
{
    long long int test, day, day2, year, year2;
    scanf("%lld", &test);
    char date[100], koma, koma2, month[100], date2[100], month2[100];
    getchar();
    for(int caseno = 1; caseno<=test; caseno++)
    {
        gets(date);
        sscanf(date, "%s %lld%c %lld", month, &day, &koma, &year);
        gets(date2);
        sscanf(date2, "%s %lld%c %lld", month2, &day2, &koma2, &year2);

        if(strcmp(month,"January")!=0 && strcmp(month,"February")!=0) year++;
        if(strcmp(month2,"January")==0 || (strcmp(month2,"February")==0 && day2<29)) year2--;
        int four = (year2/4) - ((year-1)/4);
        int hund = (year2/100) - ((year-1)/100);
        int fourhund = (year2/400) - ((year-1)/400);

        int res = four - hund + fourhund;
        printf("Case %d: %d\n", caseno, res);
    }
    return 0;
}
