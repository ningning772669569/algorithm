#include"stdio.h"
#include "stdlib.h"
#include "string.h"
/**这个题目的收获是用sprintf来进行各种转换**/
#define MAX 30
int getnext (int);
void swap(char [],int,int);
int main ()
{
    printf("%d",getnext(6174));
    return 0;
}
int getnext (int num)
{
    int a,b,c,d;
    char s[MAX];
    sprintf(s,"%d",num);
    int len =strlen (s);
    for(a=0;a<len;a++){
        for(b=0;b<len-1;b++){
            if(s[b+1]>s[b]){
                swap(s,b,b+1);
            }
        }
    }
    sscanf(s,"%d",&c);
    for(b=0;b<=(len-1)/2;b++){//在反转的时候要注意是《=才可以让他是完全反转的，不然中间的两个是没有反转的
        swap(s,b,len-1-b);
    }
    sscanf(s,"%d",&d);
    return c-d;
}
void swap(char s[],int pos1,int pos2)
{
    char store;
    store =s[pos1];
    s[pos1]=s[pos2];
    s[pos2]=store;
}
