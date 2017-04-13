#include "stdio.h"
#define MAX 3000
int s[MAX]; //为了不进行初始化数组，以喀什应该将每个数组都初始化为0
int main ()
{
    int max;
    scanf("%d",&max);
    int i,j;
    s[0]=1;
    int store;
    for(i=1;i<=n;i++){
        store=0;
        for(j=0;j<MAX;j++){
            s[j]=s[j]*i+store;
            store=s[j]/10;
            s[j]=s[j]%10;
        }
    }
    for(i=MAX-1;i>=0;i--)
}
