#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "set"
#include "vector"
#include "queue"
using namespace std;
int a[550];
int b[550];
int n,m;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int sum1=0;
        int sum2=0;
        for(int i=1;i<=m;i++)
            sum1+=a[i];
        for(int i=n;i>n-m;i--)
            sum2+=b[i];
        if(sum1>sum2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
