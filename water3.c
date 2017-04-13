#include "stdio.h"
#include "string.h"
int main ()
{
    int m,n;
    int choice;
    int pos,newnum;
    int result;
    int front,end;
    scanf("%d %d",&n,&m);
    int num[n+1];
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);

    }
    for(i=1;i<=m;i++){
        scanf("%d",&choice);
        if(choice==1){
            scanf("%d %d",&pos,&newnum);
            num[pos]=newnum;
        }else{
            scanf("%d %d",&front,&end);
            result=getmax(num,front,end);
            printf("%d\n",result);
        }
    }
}
int getmax(int num[],int front,int end)
{
    int max=num[front];
    int i;
    for(i=front;i<=end;i++){
        if(num[i]>max)
            max=num[i];
    }
    return max;
}
