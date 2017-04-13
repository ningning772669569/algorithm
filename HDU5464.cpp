#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
using namespace std;
const int maxn=1010;
const int MOD=1e9+7;
int sum[maxn];
int dp[maxn][maxn];
int num[maxn];
int N,P;
int getpos(int n,int j)
{
    if(j>n)
        return (j-n)%P;
    else
        return (j+P-n)%P;
}
int main ()
{
    //printf("%d\n",-4%3);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&N,&P);
        for(int i=1;i<=N;i++)
            scanf("%d",&num[i]);
        for(int i=1;i<=N;i++){
            num[i]%=P;
            num[i]=(num[i]+P)%P;
        }
        for(int i=1;i<=N;i++){
            int n=num[i];
            for(int j=0;j<P;j++){
                int pos=getpos(n,j);
                dp[i][j]=(sum[pos])%MOD;
                if(n==j)
                    dp[i][j]=(dp[i][j]+1)%MOD;
            }
            for(int j=0;j<P;j++)
                sum[j]=(sum[j]+dp[i][j])%MOD;
        }
        printf("%d\n",(sum[0]+1)%MOD);

    }
}
