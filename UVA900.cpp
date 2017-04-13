#include "cstdio"
#include "cstring"
#include "iostream"
#include "algorithm"
using namespace std;
typedef long long LL;
LL dp[55];
void init()
{
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=52;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }

}
int main ()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF && n){
        printf("%lld\n",dp[n]);
    }
}
