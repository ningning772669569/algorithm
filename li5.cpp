#include "cstdio"
#include "algorithm"
using namespace std;
typedef struct ant{
    int pos;
    char direction;
}ANT;
void qsort(ANT *ants,int l,int r);
const int MAX =2000;
ANT ants[MAX];
int main ()
{
    int L,T,N;
    while(scanf("%d %d %d",&L,&T,&N)==3&&T&&N&&L){
        for(int i=0;i<N;i++){
            scanf("%d %c",&ants[i].pos,&ants[i].direction);
        }
        for(int i=0;i<N;i++){
            if(ants[i].direction=='R')
                ants[i].pos=ants[i].pos+T;
            else
                ants[i].pos=ants[i].pos-T;
        }
        qsort(ants,0,N-1);
        for(int i=0;i<N;i++){
            if(ants[i].pos<0||ants[i].pos>L){
                printf("fell off \n");
            }
            else{
                printf("%d %c \n",ants[i].pos,ants[i].direction);
            }
        }
    }


}
void qsort(ANT *ants,int l,int r)
{
    int i,j,mid,midpos;
    char middir;
    ANT tep;
    i=l;
    j=r;
    mid=(i+j)/2;
    midpos=ants[mid].pos;
    middir=ants[mid].direction;
    while (i<j){
        while(j>i){
            if(ants[j].pos<midpos)
                break;
            else
                j--;
        }
        while(j>i){
            if(ants[i].pos>midpos)
                break;
            else
                i++;
        }
        if(i<j){
            tep=ants[i];
            ants[i]=ants[j];
            ants[j]=tep;
        }
    }
    if(i>l)
        qsort(ants,l,i-1);
    if(j<r)
        qsort(ants,j+1,r);
}
