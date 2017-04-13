#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL C,k1,b1,k2;
LL pow(LL a,LL b)
{
    if(b==1)
        return a;
    if(b==0)
        return 1;
    LL t=(pow(a,b/2)*pow(a,b/2))%C;
    if(b & 1)
        return (t*a)%C;
    else
        return t;
}
LL get(LL a)
{
    LL pa=pow(a,k1+b1);
    LL t=pa%C;
    t=C-t;
    return (C+t)%C;
}
int main ()
{
    int caseid=0;
    while(scanf("%I64d%I64d%I64d%I64d",&C,&k1,&b1,&k2)==4){
        caseid++;
        printf("Case #%d:\n",caseid);
        int flag=0;
        for(LL i=1;i<=C-1;i++){
            LL b=get(i);
            LL t1=pow(i,k1)%C;
            LL t2=pow(b,k2)%C;
            if(t1==t2){
                flag=1;
                printf("%I64d %I64d\n",i,b);
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
