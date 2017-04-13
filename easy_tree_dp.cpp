#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
const int maxn=400;
int N,D;
LL dp[maxn][maxn];
LL c[maxn][maxn];
void initial ()
{
    for(int i=1;i<=360;i++){
        c[i][1]=i;
        c[i][0]=1;
    }
    for(int i=2;i<=360;i++){
        for(int j=2;j<=i;j++){
            if(i==j)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
    for(int i=1;i<=360;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=360;i++)
        dp[2][i]=4;
    for(int i=3;i<=360;i++){
        double t=log(i)/log(2);
        int mindeep=t;

        if(t!=mindeep)
            mindeep++;

        for(int d=mindeep;d<=360;d++){
            dp[i][d]=c[i][1]*dp[i-1][d-1]*2;
            dp[i][d]%=MOD;
            for(int j=1;j<=i-2;j++){
                /*LL tep;
                tep=c[i][1]*c[i-2][j];
                tep%=MOD;
                tep*=dp[j][d-1];
                tep%=MOD;
                tep*=dp[i-j-1][d-1];
                tep%=MOD;
                dp[i][d]+=tep;
                dp[i][d]%=MOD;*/
                dp[i][d]=(dp[i][d]+((c[i][1]*c[i-2][j])%MOD)*((dp[j][d-1]*dp[i-1-j][d-1])%MOD)%MOD)%MOD;
            }
        }
    }

}
int main()
{
    initial();

    //cout<<c[360][180];
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&N,&D);
        printf("Case #%d: %I64d\n",t,(dp[N][D]+MOD-dp[N][D-1])%MOD);
    }

    return 0;
}
