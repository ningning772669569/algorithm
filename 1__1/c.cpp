#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL m,n;

int main ()
{
    while(scanf("%lld %lld",&m,&n)==2){
        if(m==0&&n==0)
            break;
        LL ans=0;
        int numi;
        for(int i=1;i<=min(m,n);i+=2){
            numi=i/2*2+1;
            ans=ans+(m-i+1)*(n-i+1)*i;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
