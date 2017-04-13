#include "algorithm"
#include "cstdio"
#include "iostream"
#include "cstring"
#define MAXN 3450
#define MAXM 12990
using namespace std;
typedef long long LL;
int N,M;
int dp[MAXM];
int W[MAXN];
int D[MAXN];
int main ()
{
    while(cin>>N>>M){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            cin >> W[i]>>D[i];

        }
        for(int i=0;i<=M;i++){
            if(i>=W[1])
                dp[i]=D[1];
            else
                dp[i]=0;
        }
        for(int i=2;i<=N;i++){
            for(int j=M;j>=0;j--){
                if(j>=W[i])
                    dp[j]=max(dp[j],dp[j-W[i]]+D[i]);
                else
                    dp[j]=dp[j];
            }
        }

        printf("%d\n",dp[M]);
    }
    return 0;
}
