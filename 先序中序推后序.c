#include "stdio.h"
#include "string.h"
void build (int n,char *front,char *mid,char *s);
int main ()
{
    char *s1="DBACEGF";
    char *s2="ABCDEFG";
    char s[10];
    build(7,s1,s2,s);
    s[7]='\0';
    printf("%s",s);
    return 0;
}
void build (int n,char *front,char *mid,char *s)
{
    if(n>0){
    int p=strchr(mid,front[0])-mid;
    build(p,front+1,mid,s);
    build(n-p-1,front+p+1,mid+p+1,s+p);
    s[n-1]=front[0];

    }
}
