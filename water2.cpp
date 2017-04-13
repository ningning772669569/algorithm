#include "algorithm"
#include "cstdio"
#include "string"
using namespace std;
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int max (int j,int i)
{
    if(i<j)
        return j;
    else
        return i;
}
void lsort (int pos[],int num[],int N);

void BFS(int pos[],int num[],int N);
int num[1001];
int pos[1001];
int sum;
int vis_num;
int tang[1001];
int main ()
{

    int T;
    int i;
    int N;
    int j;
    int tep;
    scanf("%d",&T);
    int result[T+1];
    for(i=1;i<=T;i++)
    {
        sum=0;
        vis_num=0;
        scanf("%d",&N);
        for(j=0;j<=1000;j++)
            tang[j]=0;
        for(j=1;j<=N;j++){
            scanf("%d",&tep);
            num[j]=tep;
            pos[j]=j;
        }
        num[0]=0;
        lsort(pos,num,N);
        BFS(pos,num,N);
        result[i]=sum;
    }
    for(i=1;i<=T;i++)
        printf("%d\n",result[i]);
        return 0;
}
void lsort (int pos[],int num[],int N)
{
    int i;
    int j;
    int tep;
    int tep_num[1001];
    for(i=1;i<=N;i++)
        tep_num[i]=num[i];
    for(i=1;i<=N;i++){
        for(j=1;j<=N-1;j++){
            if(tep_num[j]>tep_num[j+1]){
                tep=tep_num[j];
                tep_num[j]=tep_num[j+1];
                tep_num[j+1]=tep;
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
void BFS(int pos[],int num[],int N)
{
    //if(i_num>N)
    //    return;
    int i;
    int k;
    for(i=1;i<=N;i++){
    int l=0,r=0;
    if(pos[i]-1>=1)
        l=pos[i]-1;
    if(pos[i]+1<=N)
        r=pos[i]+1;
    if(l&&r)
    {
        if(tang[r]&&tang[l]){
            if(num[pos[i]]>max(num[l],num[r]))
                tang[pos[i]]=max(tang[r],tang[l])+1;
            else
                tang[pos[i]]=max(tang[r],tang[l]);
        }
        else{
            if(tang[r]){
                if(num[pos[i]]>num[r])
                    tang[pos[i]]=tang[r]+1;
                else
                    tang[pos[i]]=tang[r];
            }
            else if(tang[l]){
                if(num[pos[i]]>num[l])
                    tang[pos[i]]=tang[l]+1;
                else
                    tang[pos[i]]=tang[l];
            }
            else
                tang[pos[i]]=1;
        }
    }
    else{
        if(l)
        {
            if(tang[l]){
            if(num[pos[i]]>num[l])
                    tang[pos[i]]=tang[l]+1;
                else
                    tang[pos[i]]=tang[l];
            }
            else
                tang[pos[i]]=l;
        }
        else
        {
            if(tang[r]){
                if(num[pos[i]]>num[r])
                    tang[pos[i]]=tang[r]+1;
                else
                    tang[pos[i]]=tang[r];
            }
            else{
                //tang [pos[i]]=l;
               // k=pos[i];
                tang[pos[i]]=1;
               // tang[pos[i]]=1;
               // tang[k]=1;
                //printf("\n%d\n",k);
               // printf("%d" ,tang[pos[i]]);
            }
        }
    }
    sum=tang[pos[i]]+sum;
    //printf("%d",sum);
    //i_num++;
    //BFS(pos,num,i+1,N);
    }
}
