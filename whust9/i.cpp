#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;
int n,m;
int d[1100];
int cmp(int a,int b)
{
    return a<b;
}
int main ()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d",d[i]);
        }
        sort(d+1,d+m+1,cmp);
        int times=n/d[1];
        if(times%2)
            printf("Case #%d: Bob\n",T);
        else
            printf("Case #%d: Alice\n",T);
    }
}
