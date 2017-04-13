#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
int n;
int num[25];
int maxnum;

void iter()
{
    int tepflag=1;
    for(int i=2;i<=n;i++){

        if(num[i]!=num[1])
            {
                tepflag=0;
                break;
            }
    }
    if(tepflag)
        return ;
    tepflag=1;
    maxnum++;
    if(maxnum>1000){
        return;
    }

    int num1=num[1];
    for(int i=1;i<n;i++){
        num[i]=abs(num[i]-num[(i+1)]);
    }
    num[n]=abs(num[n]-num1);
    for(int i=2;i<=n;i++){

        if(num[i]!=num[1])
            {
                tepflag=0;
                break;
            }
    }
    if(tepflag)
        return;
    else
        iter();
}
int main ()
{
    int caseid=0;
    while(scanf("%d",&n)!=EOF&&n){
        caseid++;

        maxnum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        iter();
        if(maxnum<=1000){
            printf("Case %d: %d iterations\n",caseid,maxnum);
        }
        else
            printf("Case %d: not attained\n",caseid);
    }
    return 0;
}
