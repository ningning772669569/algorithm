#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int sum;
void boli(int num[],int start,int k,int n)
{
    int flag=0;
    if(k>=0&&start<=n){
        int i=start;
        for(i=start;i<=start+k+1&&i<=n;i++){
            if(num[i]==num[start]+1)
                {
                flag=1;
                break;
                }
        }
        if(flag){
            sum++;
            boli(num,i,k-(i-start-1),n);
        }
    }
}


int main ()
{
    int n,k;
    int num[101];

    int i;
    int max;
    while(scanf("%d %d",&n,&k)!=EOF)
    {

        max=1;
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);

        }

        for(i=1;i<=n;i++){
            sum=1;
            boli(num,i,k,n);
            if(sum>max)
                max=sum;
        }
        printf("%d\n",max);
    }
    return 0;
}
