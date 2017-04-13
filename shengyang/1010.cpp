#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=201316;
const int mod= 530600414;
LL f[maxn];
LL s[maxn];
LL d[maxn];
LL nc[maxn];
LL nn[maxn];
int main ()
{
    int T;
    scanf("%d",&T);
    f[1]=1;f[0]=1;
    for(int i=2;i<maxn;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    for(int i=3;i<maxn;i++){
        nc[i]=f[i-3];
        nn[i]=f[i];
    }
    s[3]=1;s[4]=3;s[5]=7;
    for(int i=6;i<maxn;i++){
        s[i]=((s[i-2]+s[i-1])%mod+(nc[i-1]*nn[i-2])%mod)%mod;
    }
    d[4]=0;d[5]=5;
    for(int i=6;i<maxn;i++){
        LL tepnum=s[i]-s[i-2];
        tepnum=(tepnum+mod)%mod;

        d[i]=(d[i-1]+d[i-2])%mod;
        LL tt=((nc[i-2]*tepnum)%mod+mod-(nc[i-1]*s[i-2])%mod)%mod;
        d[i]=(d[i]+tt)%mod;
    }
    for(int t=1;t<=T;t++){
        LL ask;
        scanf("%I64d",&ask);
        printf("Case #%d: %I64d\n",t,d[ask]);
    }
    return 0;
}
