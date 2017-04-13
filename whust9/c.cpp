#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
int x,n,m;
int pos[51][1001];
int cost[51][1001];
int dp[51][1001];
int main ()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d %d %d",&m,&n,&x);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&pos[i][j]);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&cost[i][j]);
            }
        }
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[1][i]=abs(pos[1][i]-x)+cost[1][i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(pos[i][j]-pos[i-1][k])+cost[i][j]);
                }
            }
        }
        int MIN=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            MIN=min(MIN,dp[m][i]);
        }
        printf("%d\n",MIN);
    }
}
