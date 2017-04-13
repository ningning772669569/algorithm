#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#define MAX 2000000
using namespace std;
typedef long long LL;

LL A,B,C;

LL getnum(LL x)
{
    return (A*x+(x%B))%C;
}
int main ()
{
    while(scanf("%I64d %I64d %I64d",&A,&B,&C)==3){
        LL slow,fast;
        slow=getnum(1);
        fast=getnum(slow);
        LL steps=1;
        for(int i=1;i<=MAX;i++){
            if(slow==fast){
                break;
            }
            slow=getnum(slow);
            fast=getnum(fast);
            fast=getnum(fast);
        }
        if(slow!=fast){
            printf("-1\n");
            continue;
        }
        slow=1;

        for(steps=0;steps<MAX;steps++){
            if(slow==fast){
                break;
            }
            slow=getnum(slow);
            fast=getnum(fast);

        }
        LL secondpos;
        int flag=0;
        for(int i=steps+1;i<MAX;i++){
            fast=getnum(fast);
            if(fast==slow){
                flag=1;
                secondpos=i;
                break;
            }
        }
        if(flag){
            printf("%I64d\n",secondpos);

        }
        else
            printf("-1\n");
    }
}
