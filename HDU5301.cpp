#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int n,m,x,y;
int getdis(int from,int to)
{
    return min(from,to-from+1);
}
int main ()
{
    while(scanf("%d%d%d%d",&n,&m,&x,&y)==4){
        int re;
        if(n>m){
            swap(n,m);
            swap(x,y);
        }
        re=(n+1)/2;
        ///n x 是短的
        if(n==m && n&1 &&x==y && x==re){
            printf("%d\n",re-1);
            continue;
        }

        if(x==re || x==re+1||y==1 || y==m)
        {
            printf("%d\n",re);
            continue;
        }

        int l=getdis(y,m);
        if(l<=re)
        {
            printf("%d\n",re);
            continue;
        }
        re=max(n-x,x-1);
        re=min(re,l);
        printf("%d\n",re);

    }
}
