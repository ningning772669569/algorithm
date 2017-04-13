#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int w[1010];
int a[1010];
int b[1010];
int dp[2010];
int N,M;
int sign[1010];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&M,&N);
        for(int i=1;i<=N;i++)
            scanf("%d %d %d",&w[i],&a[i],&b[i]);
        memset(dp,0,sizeof(dp));
        //memset(sign,0,sizeof(sign));
        for(int i=1;i<=N;i++){
        for(int v=M;v>=w[i];v--)
            dp[v]=max(dp[v],dp[v-w[i]]+a[i]+b[i]);
        for(int v=w[i];v<=M;v++){
            dp[v]=max(dp[v],dp[v-w[i]]+a[i]);
        }
        }

        printf("%d\n",dp[M]);
    }
    return 0;

}
