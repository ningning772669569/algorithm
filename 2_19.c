#include "stdio.h"


int is_leap(int);
int get_month (char *);
int get_num(int,int,int);
int main ()
{
    int T,i;
    int start_day,start_year,start_month;
    int end_day,end_year,end_month;
    char month[10];
    scanf("%d",&T);
    int result[T+1];
    for(i=1;i<=T;i++)
        result[i]=0;
    for(i=1;i<=T;i++){
        scanf("%s %d,%d",month,&start_day,&start_year);
        start_month=get_month(month);
        scanf("%s %d,%d",month,&end_day,&end_year);
        end_month=get_month(month);

        if(start_month<=2&&is_leap(start_year)){
            result[i]=1;
        }
        else
            result[i]=0;
        if(end_month>2&&is_leap(end_year))
            result[i]++;
        else if(end_month==2&&end_day==29)
            result[i]++;
        else
            ;
        result[i]=result[i]+get_num(start_year+1,end_year-1,4)-get_num(start_year+1,end_year-1,100)+get_num(start_year+1,end_year-1,400);
    }
    for(i=1;i<=T;i++)
        printf("Case #%d: %d\n",i,result[i]);
    return 0;
}
int is_leap(int year)
{
    if(year%400==0)
        return 1;
    if(year%100==0)
        return 0;
    if(year%4==0)
        return 1;
    return 0;
}
int get_month (char  month[])
{
    //January February March April May June July August September October November December
    if (month[0]=='F'||month[0]=='f')
        return 2;
    else if(month[0]=='D')
        return 12;
    else if(month[0]=='O')
        return 10;
    else if(month[0]=='S')
        return 9;
    else if(month[0]=='N')
        return 11;
    else if(month[0]=='A'){
        if(month[1]=='p')
            return 4;
        else
            return  8;
    }
    else if(month[0]=='M'){
        if(month[2]=='y')
            return 5;
        else
            return 3;
    }
    else{
        if (month[1]=='a')
            return 1;
        if(month[3]=='y')
            return 7;
        return 6;
    }
}
int get_num (int start,int end,int step)
{
    int sum=0,rest;

    if ((rest=start%step)==0)
    {

    }
    else{
        start=start+step-rest;
    }
    if((rest=end%step)==0)
    {

    }
    else {
        end=end-rest;
    }
    sum=(end-start)/step+1;
    return sum;
}
