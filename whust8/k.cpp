#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long LL;
int n,d;
const int mod=1e9+7;
LL dp[400][400];
LL c[400][400];
void initial()
{
    memset(dp,0,sizeof(dp));
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<361;i++){
        c[i][0]=1;
        c[i][1]=i;
    }
    for(int i=2;i<361;i++){
        for(int j=2;j<=i;j++){
            if(i==j)
                c[i][j]=1;
            else{
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            }
        }
    }
    for(int i=1;i<361;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<361;i++){
        int minheigh=(int)(log(i*1.0+1)/log(2.0));
        for(int j=minheigh;j<361;j++){
            dp[i][j]=(dp[i-1][j-1]*2*c[i][i-1])%mod;
            for(int k=1;k<=i-2;k++){
                dp[i][j]=(dp[i][j]+(((c[i][i-1]*c[i-2][k])%mod)*((dp[k][j-1]*dp[i-k-1][j-1])%mod)%mod))%mod;
            }
        }
    }
}
int main ()
{
    int T;
    initial();
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&n,&d);

        printf("Case #%d: %I64d\n",t,(dp[n][d]+mod-dp[n][d-1])%mod);
    }
}
