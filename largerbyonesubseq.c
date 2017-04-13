#include "stdio.h"
#include "string.h"
void lsort (int pos[],int num[],int N);

int main ()
{
    int n,k;
    int num[101];
    int pos[101];
    int tep_num[101];
    int i;
    int max;
    while(scanf("%d %d",&n,&k)==2)
    {
        int store;
        max=0;
        for(i=1;i<=n;i++){
            scanf("%d",&num[i]);
            pos[i]=i;
            tep_num[i]=num[i];
        }
        lsort(pos,tep_num,n);
        for(i=1;i<n;i++){
            store=get_num(tep_num,pos,i,k);
        }
    }
}
void lsort (int pos[],int num[],int N)
{
    int i;
    int j;

    int tep;
    for(i=1;i<=N;i++){
        for(j=1;j<=N-1;j++){
            if(num[j]>num[j+1]){
                tep=num[j];
                num[j]=num[j+1];
                num[j+1]=tep;
                tep=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=tep;
            }
        }
    }
    for(i=1;i<=N;i++)
      //  printf("%d",pos[i]);;
      ;
}
void boli(int num[],int start,int k)
{
    int i=start;
    for(i=start;i<=start+k+1;i++){
        if(num[i]==num[start]+1)
            break;
    }
    sum++;
    boli(num,i,i-start-1);
}
