#include "cstdio"
#include "cstring"
#include "algorithm"
#include "iostream"
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
LL K,N;
LL getn(LL n,LL a)
{
    if(n==1)
        return 1;
    if(n==2)
        return (n-1)/2;
    LL num=0;
    for(LL i=1;(2*i+n-1)*n<=2*a;i++){
        num=(num+getn(n-1,a-i-))%MOD;
    }
    return num;
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%lld %lld",&K,&N);
    }
}
