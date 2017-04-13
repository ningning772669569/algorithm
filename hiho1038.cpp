#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int m,n;
int dp[100001];
int val[550];
int need[550];
int main ()
{
    cin >>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&need[i],&val[i]);
    for(int i=1;i<=500;i++){
        for(int j=m;j>=need[i];j--){
            dp[j]=max(dp[j],dp[j-need[i]]+val[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}
