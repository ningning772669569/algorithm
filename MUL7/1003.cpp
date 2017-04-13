#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
const int maxn=100050;
int num[maxn];
int dp[maxn];
int n;
int main ()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(int i=1;i<n;i++){
            if(num[i]==num[i+1]){
                int j=1;
                while(i-j>=1&&i+1+j<=n&&num[i-j]==num[i+1+j]) j++;
                dp[i]=j;
            }
        }
        int MAX=0;
        for(int i=1;i<=n;i++){
            if(dp[i]){
                int pos=i+dp[i];
                if(dp[pos]==dp[i]){
                    MAX=max(MAX,3*dp[i]);
                }
            }
        }
        printf("Case #%d: %d\n",t,MAX);
    }
    return 0;
}
