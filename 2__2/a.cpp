#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
int c,t,l;
int cost[26][1001];
int dis[26][1001];
int dp[26][1001];
int main ()
{
    int Z;
    scanf("%d",&Z);
    for(int z=1;z<=Z;z++){
        scanf("%d   %d   %d",&c,&t,&l);
        for(int i=1;i<=c;i++)
            for(int j=1;j<=t;j++)
                scanf("%d %d",&dis[i][j],&cost[i][j]);

        for(int i=1;i<=t;i++)
            dp[1][i]=cost[1][i]+dis[1][i];
        for(int i=2;i<=c;i++){
            for(int j=1;j<=t;j++){
                int MIN=0x3f3f3f3f;
                for(int k=1;k<=t;k++){
                    MIN=min(dp[i-1][k]+abs(dis[i][j]-dis[i-1][k]),MIN);
                }
                dp[i][j]=MIN+cost[i][j];
            }
        }
        int re=0x3f3f3f3f;
        for(int i=1;i<=t;i++){
            re=min(re,dp[c][i]+abs(dis[c][i]-l));
        }
        printf("%d\n",re);

    }
}
