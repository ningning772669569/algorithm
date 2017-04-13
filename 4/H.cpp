#include "algorithm"
#include "cstring"
#include "cstdio"
#include "iostream"
#define MAX 105
using namespace std;
typedef long long LL;
int N;
int triangle[MAX][MAX];
int dp[MAX][MAX];
int main ()
{
    while(scanf("%d",&N)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&triangle[i][j]);
            }
        }
        for(int i=1;i<=N;i++){
            dp[N][i]=triangle[N][i];
        }
        for(int i=N-1;i>0;i--){
            for(int j=1;j<=i;j++){
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
