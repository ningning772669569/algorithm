#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#define INF 99999999
using namespace std;

int dp[35][35][910];
int v[35][35];
int N,M;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d %d",&N,&M);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                scanf("%d",&v[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        dp[1][1][v[1][1]]=v[1][1]*v[1][1];
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(i==1 && j==1)
                    continue;
                for(int k=v[i][j]+1;k<=902;k++){
                    int up=INF;
                    if(i>1){
                        if(dp[i-1][j][k-v[i][j]])
                            up=dp[i-1][j][k-v[i][j]];
                    }
                    int left=INF;
                    if(j>1){
                        if(dp[i][j-1][k-v[i][j]])
                            left=dp[i][j-1][k-v[i][j]];
                    }
                    if(up!=INF || left!=INF)
                        dp[i][j][k]=min(up,left)+v[i][j]*v[i][j];


                }
            }
        }
        int re=INF;
        for(int i=v[N][M]+1;i<=902;i++){
            if(dp[N][M][i]){
                cout<<dp[N][M][i]<<endl;
                int tep=(N+M-1)*dp[N][M][i]-i*i;
                //cout<<tep<<endl;
                re=min(re,tep);
            }
        }
        printf("Case #%d: %d\n",t,re);
    }

}
