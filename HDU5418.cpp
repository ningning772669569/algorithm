#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=1<<16-1;
int N,M;
int G[20][20];
int dp[maxn+10][17];
void floyd()
{
    for(int k=1;k<=N;k++)
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        if(G[i][j]>G[i][k]+G[k][j])
            G[i][j]=G[i][k]+G[k][j];
}
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&N,&M);
        memset(G,0x1f,sizeof(G));
        for(int i=1;i<=M;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            G[a][b]=G[b][a]=min(w,G[a][b]);
        }

        for(int i=1;i<=N;i++)   G[i][i]=0;
        floyd();
        memset(dp,0x1f,sizeof(dp));
        for(int i=1;i<=N;i++) dp[0][i]=0;
        for(int i=1;i<=((1<<N)-1);i++){
            for(int k=1;k<=N;k++){
                if((i & (1<<(k-1)))==0)
                    continue;
                int flag=0;
                for(int j=1;j<=N;j++){
                    if((i & (1<<(j-1))) && j!=k){
                            flag=1;
                            dp[i][k]=min(dp[i][k],dp[i-(1<<(k-1))][j]+G[j][k]);
                    }
                }
                if(!flag)
                    dp[i][k]=G[1][k];
            }
        }
        printf("%d\n",dp[(1<<N)-1][1]);
    }
    return 0;
}
