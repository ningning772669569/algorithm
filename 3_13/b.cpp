#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL MOD=1e9+7;
LL MAXN=1005;
LL dp [1005];
int main ()
{
    dp[1]=2;dp[2]=24;
    for(int i=3;i<=MAXN;i++){
        LL n=2*i-1;
        dp[i]=((4*n)%MOD);
        dp[i]=(dp[i-1]*dp[i])%MOD;
    }
    LL N;
    while(scanf("%I64d",&N)&&N){
        cout<<dp[N]<<endl;
    }
    return 0;
}
