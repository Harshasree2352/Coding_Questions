#include<stdio.h>
void monthname(int n)
{
        switch(n)
        {
            case 1:printf("JAN");break;
            case 2:printf("FEB");break;
            case 3:printf("MAR");break;
            case 4:printf("APR");break;
            case 5:printf("MAY");break;
            case 6:printf("JUN");break;
            case 7:printf("JUL");break;
            case 8:printf("AUG");break;
            case 9:printf("SEP");break;
            case 10:printf("OCT");break;
            case 11:printf("NOV");break;
            case 12:printf("DEC");break;
        }
}
void week(int d)
{
    switch(d)
    {
        case 0:printf("Thursday\n");break;
        case 1:printf("Friday\n");break;
        case 2:printf("Saturday\n");break;
        case 3:printf("Sunday\n");break;
        case 4:printf("Monday\n");break;
        case 5:printf("Tuesday\n");break;
        case 6:printf("Wednesday\n");break;
    }
}
int main()
{
    int n;
    printf("Enter no.of testcases : ");
    scanf("%d",&n);
    int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int leapmonths[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int years=1970;
    printf("Enter no.of seconds : ");
    for(int i=0;i<n;i++)
    {
        long int sec;
        scanf("%ld",&sec);
        int month =1;
        int days = sec / (24*60*60);
        years = years + days/365;
        int w = days%7;
        days%=365;
        if(years%400==0 || (years%4==0 && years%100!=0))
        {
            for(int j=1;j<=12;j++)
                if(leapmonths[j]<days)
                {
                    days-=leapmonths[j];
                    month++;
                }else break;
        }
        else
        {
            for(int j=1;j<=12;j++)
                if(months[j]<days)
                {
                    days-=months[j];
                    month++;
                }else break;
        }
        printf("%2d ",days+1);
        monthname(month);
        printf(" %4d ",years);
        week(w);
        
    }
}