#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=201314;
const int mod=530600414;
LL f[201315];
LL s[201315];
LL d[201315];
int main ()
{
    int T;
    scanf("%d",&T);
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=maxn;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    s[4]=3;
    s[5]=7;
    d[5]=5;
    d[4]=0;
    for(int i=6;i<=maxn;i++){
        s[i]=s[i-2]+f[i-3]*f[i-1]+s[i-1];
    }
    for(int i=6;i<=maxn;i++){
        d[i]=d[i-1]+d[i-2]+s[i-1]-s[i-2]*f[i-4]+f[i-1]*f[i-4];

    }
    for(int t=1;t<=T;t++){

    }
    printf("%d\n",d[6]);

}
