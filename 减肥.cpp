#include "cstdio"
#include "algorithm"
#include "cstring"
#include "stdio.h"
#include "iostream"
#define MAXN 101
#define MAXM 100001

using namespace std;


int dp[MAXN][MAXM];
int happy[MAXN];
int get[MAXN];
int main ()
{
    int n;
    int m;
    while(scanf("%d",&n)){
        memset(get,0,sizeof(get));
        memset(happy,0,sizeof(happy));
        for(int i=1;i<=n;i++){
            scanf("%d %d",&happy[i],&get[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(j>=get[i])
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-get[i]]+happy[i]);
                    else {
                        dp[i][j]=dp[i-1][j];
                    }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
