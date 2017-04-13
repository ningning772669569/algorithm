#include "stdio.h"
void qsort (int *,int,int);
//void swap (int num[],int pos1,int pos2);
int main ()
{
    int i;
    int num[]={6,5,2,9,3};
    qsort(num,0,4);
    for(i=0;i<4;i++){
    printf(" %d ",num[i]);
    }
    return 0;

}
void qsort (int num[],int front,int back)
{
    if(front<back)
    {
    //int mid=(back-front)/2+front;
    int i=front,j=back;
    int store=num[front];
    while(i<j){
        while(i<j&&num[j]>store){
            j--;
        }
        if(i<j){
            num[i]=num[j];
            i++;
        }
        while(i<j&&num[i]<store){
            i++;
        }

        if(i<j){
            num[j]=num[i];
            j--;
        }
    }
    num[i]=store;
    qsort(num,front,i-1);
    qsort(num,i+1,back);}
}
