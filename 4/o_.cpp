#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#define MAXN 505
#define MAXW 10010
#define INF 0x4f4f4f4f
using namespace std;
typedef long long LL;
int E,F;
int N;
int v[MAXN];
int w[MAXN];
int dp[MAXW];
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&E,&F);
        int W=F-E;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d %d",&v[i],&w[i]);
        }
        memset(dp,0x4f,sizeof(dp));
        dp[0]=0;


        for(int i=1;i<=N;i++){

            for(int j=w[i];j<=W;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[W]!=INF){
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
        }
        else{
            printf("This is impossible.\n");
        }



    }
    return 0;
}
