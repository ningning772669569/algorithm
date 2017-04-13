#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
int num[110];
int n,m;
int dp[101][20009];
bool cmp(const int &p,const int & q)
{
    return p>q;
}

int main ()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int cur=num[i];
            dp[i][cur]++;
            for(int j=cur;j<20000-cur;j++){
                dp[i][j]+=dp[i-1][j-cur]+dp[i-1][j+cur]+dp[i-1][j];
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
